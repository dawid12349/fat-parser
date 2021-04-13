
#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct disk_t* disk_open_from_file(const char* volume_file_name){
    errno = 0;
    if(volume_file_name == NULL){
        errno = EFAULT;
        return NULL;
    }
    struct disk_t* disk = (struct disk_t*)malloc(sizeof(struct disk_t));
    if(disk == NULL){
        errno = ENOMEM;
        return NULL;
    }
    disk->pdisk = fopen(volume_file_name, "rb");
    if(disk->pdisk == NULL){
        free(disk);
        errno = ENOENT;
        return NULL;
    }

    fseek(disk->pdisk, 0 , SEEK_END);
    uint32_t sec_count = (int)ftell(disk->pdisk) / (int)SECTOR_SIZE;
    disk->sec_count = sec_count;
    rewind(disk->pdisk);
    return disk;
}
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read){
    errno = 0;
    if(pdisk == NULL || buffer == NULL || pdisk->pdisk == NULL){
        errno = EFAULT;
        return -1;
    }
    if(sectors_to_read == 0 || first_sector < 0 || (first_sector > pdisk->sec_count) || (first_sector + sectors_to_read > pdisk->sec_count)){
        errno = ERANGE;
        return -1;
    }
    fseek(pdisk->pdisk, first_sector * SECTOR_SIZE, SEEK_SET);
    int32_t read = fread(buffer,SECTOR_SIZE, sectors_to_read, pdisk->pdisk );
    if(read!=sectors_to_read){
        errno = ERANGE;
        return -1;
    }
    rewind(pdisk->pdisk);
    return read;
}
int disk_close(struct disk_t* pdisk){
    errno = 0;
    if(pdisk == NULL || pdisk->pdisk == NULL){
        errno = EFAULT;
        return -1;
    }
    fclose(pdisk->pdisk);
    free(pdisk);
    return 0;
}
int validate_boot_sector(FAT_BOOT_SECTOR super, struct disk_t* disk){
    int loop_err = 0;
    for(int i =1; i<=128; i=i*2){
        if(super.sectors_per_cluster == i) {
            loop_err = 1;
            break;
        }
    }
    if(loop_err != 1) return -1;

    if(!((super.logical_sectors16 == 0 && super.logical_sectors32 != 0) || (super.logical_sectors16 !=0 && super.logical_sectors32 == 0))){
        return -1;
    }
    if(!(super.fat_count == 1 || super.fat_count == 2)){
        return -1;
    }
    if(super.fat_count == 2){
        uint32_t fat1_pos = super.reserved_sectors;
        uint32_t fat2_pos = fat1_pos + super.sectors_per_fat;
        uint8_t* fat1 = malloc(super.sectors_per_fat * super.bytes_per_sector);
        if(fat1 == NULL){
            return -1;
        }
        uint8_t* fat2 = malloc(super.sectors_per_fat * super.bytes_per_sector);
        if(fat2 == NULL){
            free(fat1);
            return -1;
        }
        if(disk_read(disk, fat1_pos, fat1, super.sectors_per_fat) == -1){
            free(fat1);
            return -1;
        }
        if(disk_read(disk, fat2_pos, fat2, super.sectors_per_fat) == -1){
            free(fat1);
            free(fat2);
            return -1;
        }
        free(fat1);
        free(fat2);
    }
    return 0;
}
uint32_t* convert_fat_table(const uint8_t* fat1, uint32_t clusters_count){
    uint32_t * fat_data = malloc(sizeof(uint32_t) * (clusters_count+1));
    if(fat_data == NULL){
        return NULL;
    }
    for(int i = 0, j = 0; i < (int)clusters_count; i += 2, j+= 3){
        uint8_t b1 = fat1[j];
        uint8_t b2 = fat1[j + 1];
        uint8_t b3 = fat1[j + 2];

        /*uint16_t n1 = ((uint16_t)(b2 & 0x0F) << 8) | b1;
        uint16_t n2 = ((uint16_t)b3 << 4) | ((b2 & 0xF0) >> 4);*/
        uint32_t n1 = ((b2 & 0x0F) << 8) | b1;
        uint32_t n2 = ((b2 & 0xF0) >> 4) | (b3 << 4);

        fat_data[i] = n1;
        fat_data[i + 1] = n2;
    }
    return fat_data;
}
struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector){
    errno = 0;
    if(pdisk == NULL || pdisk->pdisk == NULL){
        errno = EFAULT;
        return NULL;
    }
    struct volume_t* volume = malloc(sizeof(struct volume_t));
    if(volume == NULL){
        errno = ENOMEM;
        return NULL;
    }
    if(disk_read(pdisk, first_sector, &volume->super, 1) == -1){
        free(volume);
        errno = EINVAL;
        return NULL;
    }
    if(validate_boot_sector(volume->super, pdisk) == -1){
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    uint32_t fat1_pos = volume->super.reserved_sectors;
    uint32_t root_dir_pos = fat1_pos + volume->super.fat_count * volume->super.sectors_per_fat;
    uint32_t root_dir_sectors = (volume->super.root_dir_capacity * (uint32_t)sizeof(FAT_ENTRY)) / volume->super.bytes_per_sector;
    if((volume->super.root_dir_capacity * (uint32_t)sizeof(FAT_ENTRY)) % volume->super.bytes_per_sector != 0)
        root_dir_sectors += 1;
    uint32_t clusters2_pos = root_dir_pos + root_dir_sectors;
    uint32_t volume_sectors = volume->super.logical_sectors16 == 0 ? volume->super.logical_sectors32 : volume->super.logical_sectors16;
    uint32_t data_clusters = (volume_sectors - (volume->super.fat_count * volume->super.sectors_per_fat) - root_dir_sectors ) / volume->super.sectors_per_cluster;

    uint8_t* fat1 = malloc(sizeof(uint8_t) * volume->super.sectors_per_fat * volume->super.bytes_per_sector);
    if(fat1 == NULL){
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    if(disk_read(pdisk, fat1_pos, fat1, volume->super.sectors_per_fat) == -1){
        free(fat1);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    uint32_t * converted_fat = convert_fat_table(fat1, data_clusters + 2);
    if(converted_fat == NULL){
        free(fat1);
        free(volume);
        errno = ENOMEM;
        return NULL;
    }
    free(fat1);
    volume->fat1_pos = fat1_pos;
    volume->cluster2_pos = clusters2_pos;
    volume->root_pos = root_dir_pos;
    volume->root_sectors = root_dir_sectors;
    volume->disk = pdisk;
    volume->fat_table = converted_fat;
    return volume;
}
int fat_close(struct volume_t* pvolume){
    errno = 0;
    if(pvolume == NULL){
        errno = EFAULT;
        return -1;
    }
    free(pvolume->fat_table);
    free(pvolume);
    return 0;
}

char* parse_to_valid_name(char* buffer){
    int len = (int)strlen(buffer) + 2, j=0;
    char* parsed = malloc(len);
    if(parsed == NULL)
        return NULL;

    for(int i = 0; i < len; i++){
        if(isalnum(buffer[i])!=0){
            parsed[j] = buffer[i];
            j++;
        }
        if(i==7 && isalnum(buffer[8]) != 0){ //if extension exists
            parsed[j] = '.';
            j++;
        }
    }
    parsed[j] = '\0';
    return parsed;
}
struct file_t* file_open(struct volume_t* pvolume, const char* file_name){
    errno = 0;
    if(pvolume == NULL){
        errno = EFAULT;
        return NULL;
    }
    if(file_name == NULL){
        errno = ENOENT;
        return NULL;
    }
    uint32_t root_dir_buffer = pvolume->root_sectors * pvolume->super.bytes_per_sector;
    FAT_ENTRY* root_dir = malloc(root_dir_buffer);
    if(root_dir == NULL){
        errno = ENOMEM;
        return NULL;
    }
    if(disk_read(pvolume->disk, pvolume->root_pos, root_dir, pvolume->root_sectors) == -1){
        free(root_dir);
        errno = EINVAL;
        return NULL;
    }

    char buffer[12] = {0};
    buffer[11] = '\0';

    for(int i = 0; i<pvolume->super.root_dir_capacity; i++){
        memcpy(buffer, root_dir[i].name, 11);
        char* name = parse_to_valid_name(buffer);
        if(name == NULL){
            free(root_dir);
            errno = ENOMEM;
            return NULL;
        }
        if(strcmp(name, file_name) == 0){
            free(name);
            if(root_dir[i].attributes.directory || root_dir[i].attributes.volume_label){
                free(root_dir);
                errno = EISDIR;
                return NULL;
            }

            struct file_t* file = malloc(sizeof(struct file_t));
            if(file == NULL){
                free(root_dir);
                errno = ENOMEM;
                return NULL;
            }

            FAT_ENTRY* found_entry = malloc(sizeof(FAT_ENTRY));
            if(found_entry == NULL){
                free(root_dir);
                errno = ENOMEM;
                return NULL;
            }
            memcpy(found_entry, &root_dir[i], sizeof(FAT_ENTRY));
            free(root_dir);
            file->volume = pvolume;
            file->entry = found_entry;
            file->offset = 0;
            return file;
        }
        free(name);
    }
    free(root_dir);
    errno = ENOENT;
    return NULL;
}
int file_close(struct file_t* stream){
    errno = 0;
    if(stream == NULL){
        errno = EFAULT;
        return -1;
    }
    free(stream->entry);
    free(stream);
    return 0;
}
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){
    errno = 0;
    if(ptr == NULL || stream == NULL){
        errno = EFAULT;
        return -1;
    }

    if(stream->entry->size <= stream->offset){
        errno = ENXIO;
        return 0;
    }
    uint32_t file_size = 0;
    if(stream->entry->size <= size * nmemb || size * nmemb + stream->offset > stream->entry->size)
        file_size = stream->entry->size - stream->offset;
    else
        file_size = size * nmemb;

    uint32_t current = stream->entry->first_cluster_low_bytes;
    int counter = 0;
    for(; current < 0xFF8; counter++){
        current = stream->volume->fat_table[current];
    }

    uint8_t* buffer = malloc(counter * stream->volume->super.sectors_per_cluster * stream->volume->super.bytes_per_sector);
    if(buffer == NULL){
        errno = ENOMEM;
        return -1;
    }

    current = stream->entry->first_cluster_low_bytes;
    uint32_t i = 0;
    while(current < 0xFF8){
        uint32_t cluster_pos = stream->volume->cluster2_pos + (current - 2) * stream->volume->super.sectors_per_cluster;
        disk_read(stream->volume->disk, cluster_pos, buffer + i * (stream->volume->super.sectors_per_cluster * stream->volume->super.bytes_per_sector), stream->volume->super.sectors_per_cluster);
        current = stream->volume->fat_table[current];
        i++;
    }
    memcpy(ptr, buffer + stream->offset, file_size);
    stream->offset += file_size;
    free(buffer);
    return  file_size / size;
}
int32_t file_seek(struct file_t* stream, int32_t offset, int whence){
    errno = 0;
    if(stream == NULL){
        errno = EFAULT;
        return -1;
    }
    if(whence != 0 && whence != 1 && whence != 2){
        errno = EINVAL;
        return -1;
    }
    if(whence == 0){
        int k = offset;
        if(k > (int)stream->entry->size || k < 0){
            errno = ENXIO;
            return -1;
        }
        stream->offset = k;
    }
    if(whence == 1){
        int k = (int)stream->offset + offset;
        if(k > (int)stream->entry->size || k < 0){
            errno = ENXIO;
            return -1;
        }
        stream->offset = k;
    }
    if(whence == 2){
       int k = (int)stream->entry->size + offset;
       if(k > (int)stream->entry->size || k < 0){
           errno = ENXIO;
           return -1;
       }
       stream->offset = k;
    }
    return stream->offset;
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){
    errno = 0;
    if(pvolume == NULL){
        errno = EFAULT;
        return NULL;
    }
    if(dir_path == NULL || strcmp(dir_path ,"\\") != 0){
        errno = ENOENT;
        return NULL;
    }
    uint32_t root_dir_bytes = pvolume->root_sectors * pvolume->super.bytes_per_sector;
    FAT_ENTRY* root_dir = malloc(root_dir_bytes);
    if(root_dir == NULL){
        errno = ENOMEM;
        return NULL;
    }
    if(disk_read(pvolume->disk, pvolume->root_pos, root_dir, pvolume->root_sectors ) == -1){
        free(root_dir);
        return NULL;
    }
    struct dir_t* dir = malloc(sizeof(struct dir_t));
    if(dir == NULL){
        free(root_dir);
        errno = ENOMEM;
        return NULL;
    }
    dir->volume = pvolume;
    dir->entries = root_dir;
    dir->offset = 0;
    dir->capactiy = pvolume->super.root_dir_capacity;
    return dir;
}
int copy_attributes(struct dir_entry_t* entry, fat_attributes attr){
    if(attr.directory)
        entry->is_directory = 1;
    if(attr.archived)
        entry->is_archived = 1;
    if(attr.hidden_only)
        entry->is_hidden = 1;
    if(attr.system_file)
        entry->is_system = 1;
    if(attr.read_only_file)
        entry->is_readonly = 1;
    return 1;
}
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){
    errno = 0;
    if(pdir == NULL || pentry == NULL){
        errno = EFAULT;
        return -1;
    }

    if(pdir->offset >= pdir->capactiy){
        return -1;
    }


    char buffer[12] = {0};
    buffer[11] = '\0';
    for(int i = pdir->offset; i < (int)pdir->capactiy; i++){
        pdir->offset++;
        if(pdir->entries[i].name[0] == 0 )  continue;
        if(pdir->entries[i].name[0] == FAT_DELETED_MAGIC ) continue;

        memset(pentry, 0, sizeof(struct dir_entry_t));
        memcpy(buffer, pdir->entries[i].name, 11);
        char* name = parse_to_valid_name(buffer);
        strcpy(pentry->name, name);
        copy_attributes(pentry, pdir->entries[i].attributes);
        pentry->size = pdir->entries->size;
        free(name);
        return 0;
    }

    if(pdir->offset >= pdir->capactiy){
        return 1;
    }

    errno = EIO;
    return -1;
}
int dir_close(struct dir_t* pdir){
    errno = 0;
    if(pdir == NULL){
        errno = ENOMEM;
        return -1;
    }
    free(pdir->entries);
    free(pdir);
    return 0;
}


