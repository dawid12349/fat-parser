


#ifndef PROJECT1_FILE_READER_H
#define PROJECT1_FILE_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

#define SECTOR_SIZE 512
#define FAT_DELETED_MAGIC ((char)0xE5)

typedef struct {
    uint8_t  jump_code[3];
    char     oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t  sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t  fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t  media_type;
    uint16_t sectors_per_fat;
    uint16_t chs_sectors_per_track;
    uint16_t chs_tracks_per_cylinder;
    uint32_t hidden_sectors;
    uint32_t logical_sectors32;
    uint8_t  media_id;
    uint8_t  chs_head;
    uint8_t  ext_bpb_signature;
    uint32_t serial_number;
    char     volume_label[11];
    char     fsid[8];
    uint8_t  boot_code[448];
    uint16_t magic;
} __attribute__((__packed__)) FAT_BOOT_SECTOR;

/*typedef enum{ //8B
    read_only_file = 0x01,
    hidden_only = 0x02,
    system_file = 0x04,
    volume_label = 0x08,
    directory = 0x10,
    archived = 0x20,

}__attribute__((__packed__)) fat_attributes;*/

typedef struct{
    uint8_t read_only_file: 1,
    hidden_only: 1,
    system_file: 1,
    volume_label: 1,
    directory: 1,
    archived: 1,
    _reserved: 2;
}__attribute__((__packed__)) fat_attributes;


typedef struct{
    char name[11];
    fat_attributes attributes;
    uint8_t reserverd;
    uint8_t creation_time_ms;
    uint16_t creation_time;
    uint16_t creation_date;
    uint16_t last_access_date;
    uint16_t first_cluster_high_bytes; //always 0 for FAT12 FAT16
    uint16_t last_modify_time;
    uint16_t last_modify_date;
    uint16_t first_cluster_low_bytes; // to find the first cluster
    uint32_t size;
}__attribute__((__packed__)) FAT_ENTRY;

struct dir_entry_t{
    char name[13];
    uint32_t size;
    uint8_t is_archived: 1;
    uint8_t is_readonly: 1;
    uint8_t is_system: 1;
    uint8_t is_hidden: 1;
    uint8_t is_directory: 1;
};

struct disk_t{
    FILE* pdisk;
    int32_t sec_count;
};

struct volume_t {
    FAT_BOOT_SECTOR super;
    uint32_t fat1_pos;
    uint32_t root_pos;
    uint32_t root_sectors;
    uint32_t cluster2_pos;
    struct disk_t* disk;
    uint32_t* fat_table;
};

struct file_t{
    FAT_ENTRY *entry;
    struct volume_t* volume;
    uint32_t offset;
};
struct dir_t{
    FAT_ENTRY * entries;
    uint32_t capactiy;
    uint32_t offset;
    struct volume_t* volume;
};


struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);


#endif //PROJECT1_FILE_READER_H
