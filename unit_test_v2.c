/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Dawid Góra
 * Test wygenerowano automatycznie o 2020-12-12 15:28:32.440427
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("INCH.TX");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("course.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3463, 1);
                char expected_filecontent[3464] = "";
        
                strcat(expected_filecontent, "ath in his heart a purpose, he carrieth in mind the\nwhole form which his work should have; there wanteth not him\nskill and desire to bring his labour to the best effect, only the\nmatter, which he hath to work on is unframeable.\" Hooker\'s Eccl.\nPolity, b. 5.  9.\n\nCANTO II\n\nv. 1.  In small bark.]\n\nCon la barchetta mia cantando in rima\nPulci, Morg.  Magg.  c. xxviii.\n\nIo me n\'andro con la barchetta mia,\nQuanto l\'acqua comporta un picciol legno\nIbid.\n\nv. 30.  This first star.]  the moon\n\nv. 46.  E\'en as the truth.]  Like a truth that does not need\ndemonstration, but is self-evident.\"\n\nv. 52.  Cain.]  Compare Hell, Canto XX.  123. And Note\n\nv. 65.  Number1ess lights.]  The fixed stars, which differ both\nin bulk and splendor.\n\nv. 71.  Save one.]  \"Except that principle of rarity and\ndenseness which thou hast assigned.\"  By \"formal principles,\n\"principj formali, are meant constituent or essential causes.\"\nMilton, in imitation of this passage, introduces the angel\narguing with Adam respecting the causes of the spots on the moon.\n\nBut, as a late French translator of the Paradise well remarks,\nhis reasoning is physical; that of Dante partly metaphysical and\npartly theologic.\n\nv. 111.  Within the heaven.]  According to our Poet\'s system,\nthere are ten heavens; the seven planets, the eighth spheres\ncontaining the fixed stars, the primum mobile, and the empyrean.\n\nv. 143.  The virtue mingled.]  Virg. Aen. 1. vi 724.\nPrincipio coelum, &c.\n\nCANTO III\n\nv. 16.  Delusion.]  \"An error the contrary to that of Narcissus,\nbecause he mistook a shadow for a substance, I a substance for a\nshadow.\"\n\nv. 50.  Piccarda.]  The sister of Forese whom we have seen in the\nPurgatory, Canto XXIII.\n\nv. 90.  The Lady.] St. Clare, the foundress of the order called\nafter her She was born of opulent and noble parents at Assisi, in\n1193, and died in 1253.  See Biogr.  Univ. t. 1.  p. 598.  8vo.\nParis, 1813.\n\nv. 121.  Constance.]  Daughter of Ruggieri, king of Sicily, who,\nbeing taken by force out of a monastery where she had professed,\nwas married to the Emperor Henry Vl. and by him was mother to\nFrederick 11. She was fifty years old or more at the time, and\n\"because it was not credited that she could have a child at that\nage, she was delivered in a pavilion and it was given out, that\nany lady, who pleased, was at liberty to see her.  Many came, and\nsaw her, and the suspicion ceased.\"  Ricordano Malaspina in\nMuratori, Rer. It. Script. t. viii.  p. 939; and G. Villani, in\nthe same words, Hist. I v. c. 16\n\nThe French translator above mentored speaks of her having\npoisoned her husband.  The death of Henry Vl. is recorded in the\nChronicon Siciliae, by an anonymous writer, (Muratori, t. x.) but\nnot a word of his having been poisoned by Constance, and\nRicordano Malaspina even mentions her decease as happening before\nthat of her husband, Henry V., for so this author, with some\nothers, terms him. v. 122.  The second.]  Henry Vl. son of\nFrederick I was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach sou");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "EITHER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3463, file);
                test_error(size == 3463, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3463 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3463);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3463);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3365, 1);
                char expected_filecontent[3366] = "";
        
                strcat(expected_filecontent, "u sayst:  but wherefore God this way\nFor our redemption chose, eludes my search.\n     \"Brother!  no eye of man not perfected,\nNor fully ripen\'d in the flame of love,\nMay fathom this decree.  It is a mark,\nIn sooth, much aim\'d at, and but little kenn\'d:\nAnd I will therefore show thee why such way\nWas worthiest.  The celestial love, that spume\nAll envying in its bounty, in itself\nWith such effulgence blazeth, as sends forth\nAll beauteous things eternal.  What distils\nImmediate thence, no end of being knows,\nBearing its seal immutably impress\'d.\nWhatever thence immediate falls, is free,\nFree wholly, uncontrollable by power\nOf each thing new: by such conformity\nMore grateful to its author, whose bright beams,\nThough all partake their shining, yet in those\nAre liveliest, which resemble him the most.\nThese tokens of pre-eminence on man\nLargely bestow\'d, if any of them fail,\nHe needs must forfeit his nobility,\nNo longer stainless.  Sin alone is that,\nWhich doth disfranchise him, and make unlike\nTo the chief good; for that its light in him\nIs darken\'d.  And to dignity thus lost\nIs no return; unless, where guilt makes void,\nHe for ill pleasure pay with equal pain.\nYour nature, which entirely in its seed\nTrangress\'d, from these distinctions fell, no less\nThan from its state in Paradise; nor means\nFound of recovery (search all methods out\nAs strickly as thou may) save one of these,\nThe only fords were left through which to wade,\nEither that God had of his courtesy\nReleas\'d him merely, or else man himself\nFor his own folly by himself aton\'d.\n     \"Fix now thine eye, intently as thou canst,\nOn th\' everlasting counsel, and explore,\nInstructed by my words, the dread abyss.\n     \"Man in himself had ever lack\'d the means\nOf satisfaction, for he could not stoop\nObeying, in humility so low,\nAs high he, disobeying, thought to soar:\nAnd for this reason he had vainly tried\nOut of his own sufficiency to pay\nThe rigid satisfaction.  Then behooved\nThat God should by his own ways lead him back\nUnto the life, from whence he fell, restor\'d:\nBy both his ways, I mean, or one alone.\nBut since the deed is ever priz\'d the more,\nThe more the doer\'s good intent appears,\nGoodness celestial, whose broad signature\nIs on the universe, of all its ways\nTo raise ye up, was fain to leave out none,\nNor aught so vast or so magnificent,\nEither for him who gave or who receiv\'d\nBetween the last night and the primal day,\nWas or can be.  For God more bounty show\'d.\nGiving himself to make man capable\nOf his return to life, than had the terms\nBeen mere and unconditional release.\nAnd for his justice, every method else\nWere all too scant, had not the Son of God\nHumbled himself to put on mortal flesh.\n     \"Now, to fulfil each wish of thine, remains\nI somewhat further to thy view unfold.\nThat thou mayst see as clearly as myself.\n     \"I see, thou sayst, the air, the fire I see,\nThe earth and water, and all things of them\nCompounded, to corruption turn, and soon\nDissolve.  Yet these were also things create,\nBecause, if what were told me, had been true\nThey from corruption had been therefore free.\n     \"The angels, O my brother!  and this clime\nWherein thou art, impassible and pure,\nI call created, as indeed they are\nIn their whole being.  But the elements,\nWhich thou hast nam\'d, and what of them is made,\nAre by created virtue\' inform\'d: create\nTheir substance");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HIGH");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3365, file);
                test_error(size == 3365, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3365 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3365);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3365);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1656, 1);
                char expected_filecontent[1657] = "";
        
                strcat(expected_filecontent, "How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it no");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CAPITAL.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1656, file);
                test_error(size == 1656, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1656 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1656);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1656);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1536, 1);
                char expected_filecontent[1537] = "";
        
                strcat(expected_filecontent, "d one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nightly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "BROKE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1536, file);
                test_error(size == 1536, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1536 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1536);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1536);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2332, 1);
                char expected_filecontent[2333] = "";
        
                strcat(expected_filecontent, "led,\nAnd fear came o\'er me.  As with circling round\nOf turrets, Montereggion crowns his walls,\nE\'en thus the shore, encompassing th\' abyss,\nWas turreted with giants, half their length\nUprearing, horrible, whom Jove from heav\'n\nYet threatens, when his mutt\'ring thunder rolls.\n     Of one already I descried the face,\nShoulders, and breast, and of the belly huge\nGreat part, and both arms down along his ribs.\n     All-teeming nature, when her plastic hand\nLeft framing of these monsters, did display\nPast doubt her wisdom, taking from mad War\nSuch slaves to do his bidding; and if she\nRepent her not of th\' elephant and whale,\nWho ponders well confesses her therein\nWiser and more discreet; for when brute force\nAnd evil will are back\'d with subtlety,\nResistance none avails.  His visage seem\'d\nIn length and bulk, as doth the pine, that tops\nSaint Peter\'s Roman fane; and th\' other bones\nOf like proportion, so that from above\nThe bank, which girdled him below, such height\nArose his stature, that three Friezelanders\nHad striv\'n in vain to reach but to his hair.\nFull thirty ample palms was he expos\'d\nDownward from whence a man his garments loops.\n\"Raphel bai ameth sabi almi,\"\nSo shouted his fierce lips, which sweeter hymns\nBecame not; and my guide address\'d him thus:\n\"O senseless spirit!  let thy horn for thee\nInterpret:  therewith vent thy rage, if rage\nOr other passion wring thee.  Search thy neck,\nThere shalt thou find the belt that binds it on.\nWild spirit!  lo, upon thy mighty breast\nWhere hangs the baldrick!\"  Then to me he spake:\n\"He doth accuse himself.  Nimrod is this,\nThrough whose ill counsel in the world no more\nOne tongue prevails.  But pass we on, nor waste\nOur words; for so each language is to him,\nAs his to others, understood by none.\"\n     Then to the leftward turning sped we forth,\nAnd at a sling\'s throw found another shade\nFar fiercer and more huge.  I cannot say\nWhat master hand had girt him; but he held\nBehind the right arm fetter\'d, and before\nThe other with a chain, that fasten\'d him\nFrom the neck down, and five times round his form\nApparent met the wreathed links.  \"This proud one\nWould of his strength against almighty Jove\nMake trial,\" said my guide; \"whence he is thus\nRequited: Ephialtes him they call.\nGreat was his prowess, when the giants brought\nFear on the gods:  those arms, ");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "AS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2332, file);
                test_error(size == 2332, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2332 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2332);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2332);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2752, 1);
                char expected_filecontent[2753] = "";
        
                strcat(expected_filecontent, "re seal\'d on wax.  \"Fix not thy mind\nOn one place only,\" said the guide belov\'d,\nWho had me near him on that part where lies\nThe heart of man.  My sight forthwith I turn\'d\nAnd mark\'d, behind the virgin mother\'s form,\nUpon that side, where he, that mov\'d me, stood,\nAnother story graven on the rock.\n     I passed athwart the bard, and drew me near,\nThat it might stand more aptly for my view.\nThere in the self-same marble were engrav\'d\nThe cart and kine, drawing the sacred ark,\nThat from unbidden office awes mankind.\nBefore it came much people; and the whole\nParted in seven quires.  One sense cried, \"Nay,\"\nAnother, \"Yes, they sing.\"  Like doubt arose\nBetwixt the eye and smell, from the curl\'d fume\nOf incense breathing up the well-wrought toil.\nPreceding the blest vessel, onward came\nWith light dance leaping, girt in humble guise,\nSweet Israel\'s harper: in that hap he seem\'d\nLess and yet more than kingly.  Opposite,\nAt a great palace, from the lattice forth\nLook\'d Michol, like a lady full of scorn\nAnd sorrow.  To behold the tablet next,\nWhich at the hack of Michol whitely shone,\nI mov\'d me.  There was storied on the rock\nThe\' exalted glory of the Roman prince,\nWhose mighty worth mov\'d Gregory to earn\nHis mighty conquest, Trajan th\' Emperor.\nA widow at his bridle stood, attir\'d\nIn tears and mourning.  Round about them troop\'d\nFull throng of knights, and overhead in gold\nThe eagles floated, struggling with the wind.\nThe wretch appear\'d amid all these to say:\n\"Grant vengeance, sire!  for, woe beshrew this heart\nMy son is murder\'d.\"  He replying seem\'d;\n     \"Wait now till I return.\" And she, as one\nMade hasty by her grief; \"O sire, if thou\nDost not return?\"--\"Where I am, who then is,\nMay right thee.\"--\" What to thee is other\'s good,\nIf thou neglect thy own?\"--\"Now comfort thee,\"\nAt length he answers.  \"It beseemeth well\nMy duty be perform\'d, ere I move hence:\nSo justice wills; and pity bids me stay.\"\n     He, whose ken nothing new surveys, produc\'d\nThat visible speaking, new to us and strange\nThe like not found on earth.  Fondly I gaz\'d\nUpon those patterns of meek humbleness,\nShapes yet more precious for their artist\'s sake,\nWhen \"Lo,\" the poet whisper\'d, \"where this way\n(But slack their pace), a multitude advance.\nThese to the lofty steps shall guide us on.\"\n     Mine eyes, though bent on view of novel sights\nTheir lov\'d allurement, were not slow to turn.\n     Reader!  I would not that amaz\'d thou miss\nOf thy good purpose, hearing how just God\nDecrees our debts be cancel\'d.  Ponder not\nThe form of suff\'ring.  Think on what succeeds,\nThink that at worst beyond the mighty doom\nIt cannot pass.  \"Instructor,\" I began,\n\"What I see hither tending, bears no trace\nOf human semblance, nor of aught beside\nThat my foil\'");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "MOMENT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2752, file);
                test_error(size == 2752, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2752 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2752);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2752);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(89, 1);
                char expected_filecontent[90] = "";
        
                strcat(expected_filecontent, "12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considera");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CARE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 89, file);
                test_error(size == 89, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 89 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 89);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 89);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(298, 1);
                char expected_filecontent[299] = "";
        
                strcat(expected_filecontent, "ot.\"\n     Never was arrow from the cord dismiss\'d,\nThat ran its way so nimbly through the air,\nAs a small bark, that through the waves I spied\nToward us coming, under the sole sway\nOf one that ferried it, who cried aloud:\n\"Art thou arriv\'d, fell spirit?\"--\"Phlegyas, Phlegyas,\nThis time thou criest");
                
        
                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "FLOWERRU.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 298, file);
                test_error(size == 298, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 298 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 298);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 298);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3463, 1);
                char expected_filecontent[3464] = "";

                strcat(expected_filecontent, "ath in his heart a purpose, he carrieth in mind the\nwhole form which his work should have; there wanteth not him\nskill and desire to bring his labour to the best effect, only the\nmatter, which he hath to work on is unframeable.\" Hooker\'s Eccl.\nPolity, b. 5.  9.\n\nCANTO II\n\nv. 1.  In small bark.]\n\nCon la barchetta mia cantando in rima\nPulci, Morg.  Magg.  c. xxviii.\n\nIo me n\'andro con la barchetta mia,\nQuanto l\'acqua comporta un picciol legno\nIbid.\n\nv. 30.  This first star.]  the moon\n\nv. 46.  E\'en as the truth.]  Like a truth that does not need\ndemonstration, but is self-evident.\"\n\nv. 52.  Cain.]  Compare Hell, Canto XX.  123. And Note\n\nv. 65.  Number1ess lights.]  The fixed stars, which differ both\nin bulk and splendor.\n\nv. 71.  Save one.]  \"Except that principle of rarity and\ndenseness which thou hast assigned.\"  By \"formal principles,\n\"principj formali, are meant constituent or essential causes.\"\nMilton, in imitation of this passage, introduces the angel\narguing with Adam respecting the causes of the spots on the moon.\n\nBut, as a late French translator of the Paradise well remarks,\nhis reasoning is physical; that of Dante partly metaphysical and\npartly theologic.\n\nv. 111.  Within the heaven.]  According to our Poet\'s system,\nthere are ten heavens; the seven planets, the eighth spheres\ncontaining the fixed stars, the primum mobile, and the empyrean.\n\nv. 143.  The virtue mingled.]  Virg. Aen. 1. vi 724.\nPrincipio coelum, &c.\n\nCANTO III\n\nv. 16.  Delusion.]  \"An error the contrary to that of Narcissus,\nbecause he mistook a shadow for a substance, I a substance for a\nshadow.\"\n\nv. 50.  Piccarda.]  The sister of Forese whom we have seen in the\nPurgatory, Canto XXIII.\n\nv. 90.  The Lady.] St. Clare, the foundress of the order called\nafter her She was born of opulent and noble parents at Assisi, in\n1193, and died in 1253.  See Biogr.  Univ. t. 1.  p. 598.  8vo.\nParis, 1813.\n\nv. 121.  Constance.]  Daughter of Ruggieri, king of Sicily, who,\nbeing taken by force out of a monastery where she had professed,\nwas married to the Emperor Henry Vl. and by him was mother to\nFrederick 11. She was fifty years old or more at the time, and\n\"because it was not credited that she could have a child at that\nage, she was delivered in a pavilion and it was given out, that\nany lady, who pleased, was at liberty to see her.  Many came, and\nsaw her, and the suspicion ceased.\"  Ricordano Malaspina in\nMuratori, Rer. It. Script. t. viii.  p. 939; and G. Villani, in\nthe same words, Hist. I v. c. 16\n\nThe French translator above mentored speaks of her having\npoisoned her husband.  The death of Henry Vl. is recorded in the\nChronicon Siciliae, by an anonymous writer, (Muratori, t. x.) but\nnot a word of his having been poisoned by Constance, and\nRicordano Malaspina even mentions her decease as happening before\nthat of her husband, Henry V., for so this author, with some\nothers, terms him. v. 122.  The second.]  Henry Vl. son of\nFrederick I was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach sou");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "EITHER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3825, file);
                test_error(size == 3463, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3463 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3463);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3463);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3365, 1);
                char expected_filecontent[3366] = "";

                strcat(expected_filecontent, "u sayst:  but wherefore God this way\nFor our redemption chose, eludes my search.\n     \"Brother!  no eye of man not perfected,\nNor fully ripen\'d in the flame of love,\nMay fathom this decree.  It is a mark,\nIn sooth, much aim\'d at, and but little kenn\'d:\nAnd I will therefore show thee why such way\nWas worthiest.  The celestial love, that spume\nAll envying in its bounty, in itself\nWith such effulgence blazeth, as sends forth\nAll beauteous things eternal.  What distils\nImmediate thence, no end of being knows,\nBearing its seal immutably impress\'d.\nWhatever thence immediate falls, is free,\nFree wholly, uncontrollable by power\nOf each thing new: by such conformity\nMore grateful to its author, whose bright beams,\nThough all partake their shining, yet in those\nAre liveliest, which resemble him the most.\nThese tokens of pre-eminence on man\nLargely bestow\'d, if any of them fail,\nHe needs must forfeit his nobility,\nNo longer stainless.  Sin alone is that,\nWhich doth disfranchise him, and make unlike\nTo the chief good; for that its light in him\nIs darken\'d.  And to dignity thus lost\nIs no return; unless, where guilt makes void,\nHe for ill pleasure pay with equal pain.\nYour nature, which entirely in its seed\nTrangress\'d, from these distinctions fell, no less\nThan from its state in Paradise; nor means\nFound of recovery (search all methods out\nAs strickly as thou may) save one of these,\nThe only fords were left through which to wade,\nEither that God had of his courtesy\nReleas\'d him merely, or else man himself\nFor his own folly by himself aton\'d.\n     \"Fix now thine eye, intently as thou canst,\nOn th\' everlasting counsel, and explore,\nInstructed by my words, the dread abyss.\n     \"Man in himself had ever lack\'d the means\nOf satisfaction, for he could not stoop\nObeying, in humility so low,\nAs high he, disobeying, thought to soar:\nAnd for this reason he had vainly tried\nOut of his own sufficiency to pay\nThe rigid satisfaction.  Then behooved\nThat God should by his own ways lead him back\nUnto the life, from whence he fell, restor\'d:\nBy both his ways, I mean, or one alone.\nBut since the deed is ever priz\'d the more,\nThe more the doer\'s good intent appears,\nGoodness celestial, whose broad signature\nIs on the universe, of all its ways\nTo raise ye up, was fain to leave out none,\nNor aught so vast or so magnificent,\nEither for him who gave or who receiv\'d\nBetween the last night and the primal day,\nWas or can be.  For God more bounty show\'d.\nGiving himself to make man capable\nOf his return to life, than had the terms\nBeen mere and unconditional release.\nAnd for his justice, every method else\nWere all too scant, had not the Son of God\nHumbled himself to put on mortal flesh.\n     \"Now, to fulfil each wish of thine, remains\nI somewhat further to thy view unfold.\nThat thou mayst see as clearly as myself.\n     \"I see, thou sayst, the air, the fire I see,\nThe earth and water, and all things of them\nCompounded, to corruption turn, and soon\nDissolve.  Yet these were also things create,\nBecause, if what were told me, had been true\nThey from corruption had been therefore free.\n     \"The angels, O my brother!  and this clime\nWherein thou art, impassible and pure,\nI call created, as indeed they are\nIn their whole being.  But the elements,\nWhich thou hast nam\'d, and what of them is made,\nAre by created virtue\' inform\'d: create\nTheir substance");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HIGH");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3703, file);
                test_error(size == 3365, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3365 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3365);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3365);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1656, 1);
                char expected_filecontent[1657] = "";

                strcat(expected_filecontent, "How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it no");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CAPITAL.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2036, file);
                test_error(size == 1656, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1656 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1656);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1656);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1536, 1);
                char expected_filecontent[1537] = "";

                strcat(expected_filecontent, "d one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nightly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BROKE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1701, file);
                test_error(size == 1536, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1536 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1536);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1536);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2332, 1);
                char expected_filecontent[2333] = "";

                strcat(expected_filecontent, "led,\nAnd fear came o\'er me.  As with circling round\nOf turrets, Montereggion crowns his walls,\nE\'en thus the shore, encompassing th\' abyss,\nWas turreted with giants, half their length\nUprearing, horrible, whom Jove from heav\'n\nYet threatens, when his mutt\'ring thunder rolls.\n     Of one already I descried the face,\nShoulders, and breast, and of the belly huge\nGreat part, and both arms down along his ribs.\n     All-teeming nature, when her plastic hand\nLeft framing of these monsters, did display\nPast doubt her wisdom, taking from mad War\nSuch slaves to do his bidding; and if she\nRepent her not of th\' elephant and whale,\nWho ponders well confesses her therein\nWiser and more discreet; for when brute force\nAnd evil will are back\'d with subtlety,\nResistance none avails.  His visage seem\'d\nIn length and bulk, as doth the pine, that tops\nSaint Peter\'s Roman fane; and th\' other bones\nOf like proportion, so that from above\nThe bank, which girdled him below, such height\nArose his stature, that three Friezelanders\nHad striv\'n in vain to reach but to his hair.\nFull thirty ample palms was he expos\'d\nDownward from whence a man his garments loops.\n\"Raphel bai ameth sabi almi,\"\nSo shouted his fierce lips, which sweeter hymns\nBecame not; and my guide address\'d him thus:\n\"O senseless spirit!  let thy horn for thee\nInterpret:  therewith vent thy rage, if rage\nOr other passion wring thee.  Search thy neck,\nThere shalt thou find the belt that binds it on.\nWild spirit!  lo, upon thy mighty breast\nWhere hangs the baldrick!\"  Then to me he spake:\n\"He doth accuse himself.  Nimrod is this,\nThrough whose ill counsel in the world no more\nOne tongue prevails.  But pass we on, nor waste\nOur words; for so each language is to him,\nAs his to others, understood by none.\"\n     Then to the leftward turning sped we forth,\nAnd at a sling\'s throw found another shade\nFar fiercer and more huge.  I cannot say\nWhat master hand had girt him; but he held\nBehind the right arm fetter\'d, and before\nThe other with a chain, that fasten\'d him\nFrom the neck down, and five times round his form\nApparent met the wreathed links.  \"This proud one\nWould of his strength against almighty Jove\nMake trial,\" said my guide; \"whence he is thus\nRequited: Ephialtes him they call.\nGreat was his prowess, when the giants brought\nFear on the gods:  those arms, ");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "AS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2722, file);
                test_error(size == 2332, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2332 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2332);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2332);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2752, 1);
                char expected_filecontent[2753] = "";

                strcat(expected_filecontent, "re seal\'d on wax.  \"Fix not thy mind\nOn one place only,\" said the guide belov\'d,\nWho had me near him on that part where lies\nThe heart of man.  My sight forthwith I turn\'d\nAnd mark\'d, behind the virgin mother\'s form,\nUpon that side, where he, that mov\'d me, stood,\nAnother story graven on the rock.\n     I passed athwart the bard, and drew me near,\nThat it might stand more aptly for my view.\nThere in the self-same marble were engrav\'d\nThe cart and kine, drawing the sacred ark,\nThat from unbidden office awes mankind.\nBefore it came much people; and the whole\nParted in seven quires.  One sense cried, \"Nay,\"\nAnother, \"Yes, they sing.\"  Like doubt arose\nBetwixt the eye and smell, from the curl\'d fume\nOf incense breathing up the well-wrought toil.\nPreceding the blest vessel, onward came\nWith light dance leaping, girt in humble guise,\nSweet Israel\'s harper: in that hap he seem\'d\nLess and yet more than kingly.  Opposite,\nAt a great palace, from the lattice forth\nLook\'d Michol, like a lady full of scorn\nAnd sorrow.  To behold the tablet next,\nWhich at the hack of Michol whitely shone,\nI mov\'d me.  There was storied on the rock\nThe\' exalted glory of the Roman prince,\nWhose mighty worth mov\'d Gregory to earn\nHis mighty conquest, Trajan th\' Emperor.\nA widow at his bridle stood, attir\'d\nIn tears and mourning.  Round about them troop\'d\nFull throng of knights, and overhead in gold\nThe eagles floated, struggling with the wind.\nThe wretch appear\'d amid all these to say:\n\"Grant vengeance, sire!  for, woe beshrew this heart\nMy son is murder\'d.\"  He replying seem\'d;\n     \"Wait now till I return.\" And she, as one\nMade hasty by her grief; \"O sire, if thou\nDost not return?\"--\"Where I am, who then is,\nMay right thee.\"--\" What to thee is other\'s good,\nIf thou neglect thy own?\"--\"Now comfort thee,\"\nAt length he answers.  \"It beseemeth well\nMy duty be perform\'d, ere I move hence:\nSo justice wills; and pity bids me stay.\"\n     He, whose ken nothing new surveys, produc\'d\nThat visible speaking, new to us and strange\nThe like not found on earth.  Fondly I gaz\'d\nUpon those patterns of meek humbleness,\nShapes yet more precious for their artist\'s sake,\nWhen \"Lo,\" the poet whisper\'d, \"where this way\n(But slack their pace), a multitude advance.\nThese to the lofty steps shall guide us on.\"\n     Mine eyes, though bent on view of novel sights\nTheir lov\'d allurement, were not slow to turn.\n     Reader!  I would not that amaz\'d thou miss\nOf thy good purpose, hearing how just God\nDecrees our debts be cancel\'d.  Ponder not\nThe form of suff\'ring.  Think on what succeeds,\nThink that at worst beyond the mighty doom\nIt cannot pass.  \"Instructor,\" I began,\n\"What I see hither tending, bears no trace\nOf human semblance, nor of aught beside\nThat my foil\'");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MOMENT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3025, file);
                test_error(size == 2752, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2752 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2752);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2752);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(89, 1);
                char expected_filecontent[90] = "";

                strcat(expected_filecontent, "12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considera");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CARE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 460, file);
                test_error(size == 89, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 89 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 89);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 89);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(298, 1);
                char expected_filecontent[299] = "";

                strcat(expected_filecontent, "ot.\"\n     Never was arrow from the cord dismiss\'d,\nThat ran its way so nimbly through the air,\nAs a small bark, that through the waves I spied\nToward us coming, under the sole sway\nOf one that ferried it, who cried aloud:\n\"Art thou arriv\'d, fell spirit?\"--\"Phlegyas, Phlegyas,\nThis time thou criest");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FLOWERRU.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 454, file);
                test_error(size == 298, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 298 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 298);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 298);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3464] = "";

                strcat(expected_filecontent, "ath in his heart a purpose, he carrieth in mind the\nwhole form which his work should have; there wanteth not him\nskill and desire to bring his labour to the best effect, only the\nmatter, which he hath to work on is unframeable.\" Hooker\'s Eccl.\nPolity, b. 5.  9.\n\nCANTO II\n\nv. 1.  In small bark.]\n\nCon la barchetta mia cantando in rima\nPulci, Morg.  Magg.  c. xxviii.\n\nIo me n\'andro con la barchetta mia,\nQuanto l\'acqua comporta un picciol legno\nIbid.\n\nv. 30.  This first star.]  the moon\n\nv. 46.  E\'en as the truth.]  Like a truth that does not need\ndemonstration, but is self-evident.\"\n\nv. 52.  Cain.]  Compare Hell, Canto XX.  123. And Note\n\nv. 65.  Number1ess lights.]  The fixed stars, which differ both\nin bulk and splendor.\n\nv. 71.  Save one.]  \"Except that principle of rarity and\ndenseness which thou hast assigned.\"  By \"formal principles,\n\"principj formali, are meant constituent or essential causes.\"\nMilton, in imitation of this passage, introduces the angel\narguing with Adam respecting the causes of the spots on the moon.\n\nBut, as a late French translator of the Paradise well remarks,\nhis reasoning is physical; that of Dante partly metaphysical and\npartly theologic.\n\nv. 111.  Within the heaven.]  According to our Poet\'s system,\nthere are ten heavens; the seven planets, the eighth spheres\ncontaining the fixed stars, the primum mobile, and the empyrean.\n\nv. 143.  The virtue mingled.]  Virg. Aen. 1. vi 724.\nPrincipio coelum, &c.\n\nCANTO III\n\nv. 16.  Delusion.]  \"An error the contrary to that of Narcissus,\nbecause he mistook a shadow for a substance, I a substance for a\nshadow.\"\n\nv. 50.  Piccarda.]  The sister of Forese whom we have seen in the\nPurgatory, Canto XXIII.\n\nv. 90.  The Lady.] St. Clare, the foundress of the order called\nafter her She was born of opulent and noble parents at Assisi, in\n1193, and died in 1253.  See Biogr.  Univ. t. 1.  p. 598.  8vo.\nParis, 1813.\n\nv. 121.  Constance.]  Daughter of Ruggieri, king of Sicily, who,\nbeing taken by force out of a monastery where she had professed,\nwas married to the Emperor Henry Vl. and by him was mother to\nFrederick 11. She was fifty years old or more at the time, and\n\"because it was not credited that she could have a child at that\nage, she was delivered in a pavilion and it was given out, that\nany lady, who pleased, was at liberty to see her.  Many came, and\nsaw her, and the suspicion ceased.\"  Ricordano Malaspina in\nMuratori, Rer. It. Script. t. viii.  p. 939; and G. Villani, in\nthe same words, Hist. I v. c. 16\n\nThe French translator above mentored speaks of her having\npoisoned her husband.  The death of Henry Vl. is recorded in the\nChronicon Siciliae, by an anonymous writer, (Muratori, t. x.) but\nnot a word of his having been poisoned by Constance, and\nRicordano Malaspina even mentions her decease as happening before\nthat of her husband, Henry V., for so this author, with some\nothers, terms him. v. 122.  The second.]  Henry Vl. son of\nFrederick I was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach sou");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "EITHER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3463; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3366] = "";

                strcat(expected_filecontent, "u sayst:  but wherefore God this way\nFor our redemption chose, eludes my search.\n     \"Brother!  no eye of man not perfected,\nNor fully ripen\'d in the flame of love,\nMay fathom this decree.  It is a mark,\nIn sooth, much aim\'d at, and but little kenn\'d:\nAnd I will therefore show thee why such way\nWas worthiest.  The celestial love, that spume\nAll envying in its bounty, in itself\nWith such effulgence blazeth, as sends forth\nAll beauteous things eternal.  What distils\nImmediate thence, no end of being knows,\nBearing its seal immutably impress\'d.\nWhatever thence immediate falls, is free,\nFree wholly, uncontrollable by power\nOf each thing new: by such conformity\nMore grateful to its author, whose bright beams,\nThough all partake their shining, yet in those\nAre liveliest, which resemble him the most.\nThese tokens of pre-eminence on man\nLargely bestow\'d, if any of them fail,\nHe needs must forfeit his nobility,\nNo longer stainless.  Sin alone is that,\nWhich doth disfranchise him, and make unlike\nTo the chief good; for that its light in him\nIs darken\'d.  And to dignity thus lost\nIs no return; unless, where guilt makes void,\nHe for ill pleasure pay with equal pain.\nYour nature, which entirely in its seed\nTrangress\'d, from these distinctions fell, no less\nThan from its state in Paradise; nor means\nFound of recovery (search all methods out\nAs strickly as thou may) save one of these,\nThe only fords were left through which to wade,\nEither that God had of his courtesy\nReleas\'d him merely, or else man himself\nFor his own folly by himself aton\'d.\n     \"Fix now thine eye, intently as thou canst,\nOn th\' everlasting counsel, and explore,\nInstructed by my words, the dread abyss.\n     \"Man in himself had ever lack\'d the means\nOf satisfaction, for he could not stoop\nObeying, in humility so low,\nAs high he, disobeying, thought to soar:\nAnd for this reason he had vainly tried\nOut of his own sufficiency to pay\nThe rigid satisfaction.  Then behooved\nThat God should by his own ways lead him back\nUnto the life, from whence he fell, restor\'d:\nBy both his ways, I mean, or one alone.\nBut since the deed is ever priz\'d the more,\nThe more the doer\'s good intent appears,\nGoodness celestial, whose broad signature\nIs on the universe, of all its ways\nTo raise ye up, was fain to leave out none,\nNor aught so vast or so magnificent,\nEither for him who gave or who receiv\'d\nBetween the last night and the primal day,\nWas or can be.  For God more bounty show\'d.\nGiving himself to make man capable\nOf his return to life, than had the terms\nBeen mere and unconditional release.\nAnd for his justice, every method else\nWere all too scant, had not the Son of God\nHumbled himself to put on mortal flesh.\n     \"Now, to fulfil each wish of thine, remains\nI somewhat further to thy view unfold.\nThat thou mayst see as clearly as myself.\n     \"I see, thou sayst, the air, the fire I see,\nThe earth and water, and all things of them\nCompounded, to corruption turn, and soon\nDissolve.  Yet these were also things create,\nBecause, if what were told me, had been true\nThey from corruption had been therefore free.\n     \"The angels, O my brother!  and this clime\nWherein thou art, impassible and pure,\nI call created, as indeed they are\nIn their whole being.  But the elements,\nWhich thou hast nam\'d, and what of them is made,\nAre by created virtue\' inform\'d: create\nTheir substance");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HIGH");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3365; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1657] = "";

                strcat(expected_filecontent, "How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it no");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CAPITAL.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1656; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1537] = "";

                strcat(expected_filecontent, "d one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nightly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BROKE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1536; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2333] = "";

                strcat(expected_filecontent, "led,\nAnd fear came o\'er me.  As with circling round\nOf turrets, Montereggion crowns his walls,\nE\'en thus the shore, encompassing th\' abyss,\nWas turreted with giants, half their length\nUprearing, horrible, whom Jove from heav\'n\nYet threatens, when his mutt\'ring thunder rolls.\n     Of one already I descried the face,\nShoulders, and breast, and of the belly huge\nGreat part, and both arms down along his ribs.\n     All-teeming nature, when her plastic hand\nLeft framing of these monsters, did display\nPast doubt her wisdom, taking from mad War\nSuch slaves to do his bidding; and if she\nRepent her not of th\' elephant and whale,\nWho ponders well confesses her therein\nWiser and more discreet; for when brute force\nAnd evil will are back\'d with subtlety,\nResistance none avails.  His visage seem\'d\nIn length and bulk, as doth the pine, that tops\nSaint Peter\'s Roman fane; and th\' other bones\nOf like proportion, so that from above\nThe bank, which girdled him below, such height\nArose his stature, that three Friezelanders\nHad striv\'n in vain to reach but to his hair.\nFull thirty ample palms was he expos\'d\nDownward from whence a man his garments loops.\n\"Raphel bai ameth sabi almi,\"\nSo shouted his fierce lips, which sweeter hymns\nBecame not; and my guide address\'d him thus:\n\"O senseless spirit!  let thy horn for thee\nInterpret:  therewith vent thy rage, if rage\nOr other passion wring thee.  Search thy neck,\nThere shalt thou find the belt that binds it on.\nWild spirit!  lo, upon thy mighty breast\nWhere hangs the baldrick!\"  Then to me he spake:\n\"He doth accuse himself.  Nimrod is this,\nThrough whose ill counsel in the world no more\nOne tongue prevails.  But pass we on, nor waste\nOur words; for so each language is to him,\nAs his to others, understood by none.\"\n     Then to the leftward turning sped we forth,\nAnd at a sling\'s throw found another shade\nFar fiercer and more huge.  I cannot say\nWhat master hand had girt him; but he held\nBehind the right arm fetter\'d, and before\nThe other with a chain, that fasten\'d him\nFrom the neck down, and five times round his form\nApparent met the wreathed links.  \"This proud one\nWould of his strength against almighty Jove\nMake trial,\" said my guide; \"whence he is thus\nRequited: Ephialtes him they call.\nGreat was his prowess, when the giants brought\nFear on the gods:  those arms, ");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "AS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2332; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2753] = "";

                strcat(expected_filecontent, "re seal\'d on wax.  \"Fix not thy mind\nOn one place only,\" said the guide belov\'d,\nWho had me near him on that part where lies\nThe heart of man.  My sight forthwith I turn\'d\nAnd mark\'d, behind the virgin mother\'s form,\nUpon that side, where he, that mov\'d me, stood,\nAnother story graven on the rock.\n     I passed athwart the bard, and drew me near,\nThat it might stand more aptly for my view.\nThere in the self-same marble were engrav\'d\nThe cart and kine, drawing the sacred ark,\nThat from unbidden office awes mankind.\nBefore it came much people; and the whole\nParted in seven quires.  One sense cried, \"Nay,\"\nAnother, \"Yes, they sing.\"  Like doubt arose\nBetwixt the eye and smell, from the curl\'d fume\nOf incense breathing up the well-wrought toil.\nPreceding the blest vessel, onward came\nWith light dance leaping, girt in humble guise,\nSweet Israel\'s harper: in that hap he seem\'d\nLess and yet more than kingly.  Opposite,\nAt a great palace, from the lattice forth\nLook\'d Michol, like a lady full of scorn\nAnd sorrow.  To behold the tablet next,\nWhich at the hack of Michol whitely shone,\nI mov\'d me.  There was storied on the rock\nThe\' exalted glory of the Roman prince,\nWhose mighty worth mov\'d Gregory to earn\nHis mighty conquest, Trajan th\' Emperor.\nA widow at his bridle stood, attir\'d\nIn tears and mourning.  Round about them troop\'d\nFull throng of knights, and overhead in gold\nThe eagles floated, struggling with the wind.\nThe wretch appear\'d amid all these to say:\n\"Grant vengeance, sire!  for, woe beshrew this heart\nMy son is murder\'d.\"  He replying seem\'d;\n     \"Wait now till I return.\" And she, as one\nMade hasty by her grief; \"O sire, if thou\nDost not return?\"--\"Where I am, who then is,\nMay right thee.\"--\" What to thee is other\'s good,\nIf thou neglect thy own?\"--\"Now comfort thee,\"\nAt length he answers.  \"It beseemeth well\nMy duty be perform\'d, ere I move hence:\nSo justice wills; and pity bids me stay.\"\n     He, whose ken nothing new surveys, produc\'d\nThat visible speaking, new to us and strange\nThe like not found on earth.  Fondly I gaz\'d\nUpon those patterns of meek humbleness,\nShapes yet more precious for their artist\'s sake,\nWhen \"Lo,\" the poet whisper\'d, \"where this way\n(But slack their pace), a multitude advance.\nThese to the lofty steps shall guide us on.\"\n     Mine eyes, though bent on view of novel sights\nTheir lov\'d allurement, were not slow to turn.\n     Reader!  I would not that amaz\'d thou miss\nOf thy good purpose, hearing how just God\nDecrees our debts be cancel\'d.  Ponder not\nThe form of suff\'ring.  Think on what succeeds,\nThink that at worst beyond the mighty doom\nIt cannot pass.  \"Instructor,\" I began,\n\"What I see hither tending, bears no trace\nOf human semblance, nor of aught beside\nThat my foil\'");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MOMENT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2752; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[90] = "";

                strcat(expected_filecontent, "12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considera");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CARE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 89; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[299] = "";

                strcat(expected_filecontent, "ot.\"\n     Never was arrow from the cord dismiss\'d,\nThat ran its way so nimbly through the air,\nAs a small bark, that through the waves I spied\nToward us coming, under the sole sway\nOf one that ferried it, who cried aloud:\n\"Art thou arriv\'d, fell spirit?\"--\"Phlegyas, Phlegyas,\nThis time thou criest");

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FLOWERRU.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 298; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(298, 1);
            char expected_filecontent[299] = "";

            strcat(expected_filecontent, "ot.\"\n     Never was arrow from the cord dismiss\'d,\nThat ran its way so nimbly through the air,\nAs a small bark, that through the waves I spied\nToward us coming, under the sole sway\nOf one that ferried it, who cried aloud:\n\"Art thou arriv\'d, fell spirit?\"--\"Phlegyas, Phlegyas,\nThis time thou criest");

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FLOWERRU.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 18; ++i)
            {
                int res = file_read(filecontent + 16 * i, 16, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 16 * i, 16, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 298);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 298);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(3463, 1);
    char *filecontent1 = (char *)calloc(3365, 1);
    char *filecontent2 = (char *)calloc(1656, 1);
    char *filecontent3 = (char *)calloc(1536, 1);
    char *filecontent4 = (char *)calloc(2332, 1);
    char *filecontent5 = (char *)calloc(2752, 1);
    char *filecontent6 = (char *)calloc(89, 1);
    char *filecontent7 = (char *)calloc(298, 1);

            char expected_filecontent0[3464] = "";
    char expected_filecontent1[3366] = "";
    char expected_filecontent2[1657] = "";
    char expected_filecontent3[1537] = "";
    char expected_filecontent4[2333] = "";
    char expected_filecontent5[2753] = "";
    char expected_filecontent6[90] = "";
    char expected_filecontent7[299] = "";

            strcat(expected_filecontent0, "ath in his heart a purpose, he carrieth in mind the\nwhole form which his work should have; there wanteth not him\nskill and desire to bring his labour to the best effect, only the\nmatter, which he hath to work on is unframeable.\" Hooker\'s Eccl.\nPolity, b. 5.  9.\n\nCANTO II\n\nv. 1.  In small bark.]\n\nCon la barchetta mia cantando in rima\nPulci, Morg.  Magg.  c. xxviii.\n\nIo me n\'andro con la barchetta mia,\nQuanto l\'acqua comporta un picciol legno\nIbid.\n\nv. 30.  This first star.]  the moon\n\nv. 46.  E\'en as the truth.]  Like a truth that does not need\ndemonstration, but is self-evident.\"\n\nv. 52.  Cain.]  Compare Hell, Canto XX.  123. And Note\n\nv. 65.  Number1ess lights.]  The fixed stars, which differ both\nin bulk and splendor.\n\nv. 71.  Save one.]  \"Except that principle of rarity and\ndenseness which thou hast assigned.\"  By \"formal principles,\n\"principj formali, are meant constituent or essential causes.\"\nMilton, in imitation of this passage, introduces the angel\narguing with Adam respecting the causes of the spots on the moon.\n\nBut, as a late French translator of the Paradise well remarks,\nhis reasoning is physical; that of Dante partly metaphysical and\npartly theologic.\n\nv. 111.  Within the heaven.]  According to our Poet\'s system,\nthere are ten heavens; the seven planets, the eighth spheres\ncontaining the fixed stars, the primum mobile, and the empyrean.\n\nv. 143.  The virtue mingled.]  Virg. Aen. 1. vi 724.\nPrincipio coelum, &c.\n\nCANTO III\n\nv. 16.  Delusion.]  \"An error the contrary to that of Narcissus,\nbecause he mistook a shadow for a substance, I a substance for a\nshadow.\"\n\nv. 50.  Piccarda.]  The sister of Forese whom we have seen in the\nPurgatory, Canto XXIII.\n\nv. 90.  The Lady.] St. Clare, the foundress of the order called\nafter her She was born of opulent and noble parents at Assisi, in\n1193, and died in 1253.  See Biogr.  Univ. t. 1.  p. 598.  8vo.\nParis, 1813.\n\nv. 121.  Constance.]  Daughter of Ruggieri, king of Sicily, who,\nbeing taken by force out of a monastery where she had professed,\nwas married to the Emperor Henry Vl. and by him was mother to\nFrederick 11. She was fifty years old or more at the time, and\n\"because it was not credited that she could have a child at that\nage, she was delivered in a pavilion and it was given out, that\nany lady, who pleased, was at liberty to see her.  Many came, and\nsaw her, and the suspicion ceased.\"  Ricordano Malaspina in\nMuratori, Rer. It. Script. t. viii.  p. 939; and G. Villani, in\nthe same words, Hist. I v. c. 16\n\nThe French translator above mentored speaks of her having\npoisoned her husband.  The death of Henry Vl. is recorded in the\nChronicon Siciliae, by an anonymous writer, (Muratori, t. x.) but\nnot a word of his having been poisoned by Constance, and\nRicordano Malaspina even mentions her decease as happening before\nthat of her husband, Henry V., for so this author, with some\nothers, terms him. v. 122.  The second.]  Henry Vl. son of\nFrederick I was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach sou");strcat(expected_filecontent1, "u sayst:  but wherefore God this way\nFor our redemption chose, eludes my search.\n     \"Brother!  no eye of man not perfected,\nNor fully ripen\'d in the flame of love,\nMay fathom this decree.  It is a mark,\nIn sooth, much aim\'d at, and but little kenn\'d:\nAnd I will therefore show thee why such way\nWas worthiest.  The celestial love, that spume\nAll envying in its bounty, in itself\nWith such effulgence blazeth, as sends forth\nAll beauteous things eternal.  What distils\nImmediate thence, no end of being knows,\nBearing its seal immutably impress\'d.\nWhatever thence immediate falls, is free,\nFree wholly, uncontrollable by power\nOf each thing new: by such conformity\nMore grateful to its author, whose bright beams,\nThough all partake their shining, yet in those\nAre liveliest, which resemble him the most.\nThese tokens of pre-eminence on man\nLargely bestow\'d, if any of them fail,\nHe needs must forfeit his nobility,\nNo longer stainless.  Sin alone is that,\nWhich doth disfranchise him, and make unlike\nTo the chief good; for that its light in him\nIs darken\'d.  And to dignity thus lost\nIs no return; unless, where guilt makes void,\nHe for ill pleasure pay with equal pain.\nYour nature, which entirely in its seed\nTrangress\'d, from these distinctions fell, no less\nThan from its state in Paradise; nor means\nFound of recovery (search all methods out\nAs strickly as thou may) save one of these,\nThe only fords were left through which to wade,\nEither that God had of his courtesy\nReleas\'d him merely, or else man himself\nFor his own folly by himself aton\'d.\n     \"Fix now thine eye, intently as thou canst,\nOn th\' everlasting counsel, and explore,\nInstructed by my words, the dread abyss.\n     \"Man in himself had ever lack\'d the means\nOf satisfaction, for he could not stoop\nObeying, in humility so low,\nAs high he, disobeying, thought to soar:\nAnd for this reason he had vainly tried\nOut of his own sufficiency to pay\nThe rigid satisfaction.  Then behooved\nThat God should by his own ways lead him back\nUnto the life, from whence he fell, restor\'d:\nBy both his ways, I mean, or one alone.\nBut since the deed is ever priz\'d the more,\nThe more the doer\'s good intent appears,\nGoodness celestial, whose broad signature\nIs on the universe, of all its ways\nTo raise ye up, was fain to leave out none,\nNor aught so vast or so magnificent,\nEither for him who gave or who receiv\'d\nBetween the last night and the primal day,\nWas or can be.  For God more bounty show\'d.\nGiving himself to make man capable\nOf his return to life, than had the terms\nBeen mere and unconditional release.\nAnd for his justice, every method else\nWere all too scant, had not the Son of God\nHumbled himself to put on mortal flesh.\n     \"Now, to fulfil each wish of thine, remains\nI somewhat further to thy view unfold.\nThat thou mayst see as clearly as myself.\n     \"I see, thou sayst, the air, the fire I see,\nThe earth and water, and all things of them\nCompounded, to corruption turn, and soon\nDissolve.  Yet these were also things create,\nBecause, if what were told me, had been true\nThey from corruption had been therefore free.\n     \"The angels, O my brother!  and this clime\nWherein thou art, impassible and pure,\nI call created, as indeed they are\nIn their whole being.  But the elements,\nWhich thou hast nam\'d, and what of them is made,\nAre by created virtue\' inform\'d: create\nTheir substance");strcat(expected_filecontent2, "How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it no");strcat(expected_filecontent3, "d one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nightly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part");strcat(expected_filecontent4, "led,\nAnd fear came o\'er me.  As with circling round\nOf turrets, Montereggion crowns his walls,\nE\'en thus the shore, encompassing th\' abyss,\nWas turreted with giants, half their length\nUprearing, horrible, whom Jove from heav\'n\nYet threatens, when his mutt\'ring thunder rolls.\n     Of one already I descried the face,\nShoulders, and breast, and of the belly huge\nGreat part, and both arms down along his ribs.\n     All-teeming nature, when her plastic hand\nLeft framing of these monsters, did display\nPast doubt her wisdom, taking from mad War\nSuch slaves to do his bidding; and if she\nRepent her not of th\' elephant and whale,\nWho ponders well confesses her therein\nWiser and more discreet; for when brute force\nAnd evil will are back\'d with subtlety,\nResistance none avails.  His visage seem\'d\nIn length and bulk, as doth the pine, that tops\nSaint Peter\'s Roman fane; and th\' other bones\nOf like proportion, so that from above\nThe bank, which girdled him below, such height\nArose his stature, that three Friezelanders\nHad striv\'n in vain to reach but to his hair.\nFull thirty ample palms was he expos\'d\nDownward from whence a man his garments loops.\n\"Raphel bai ameth sabi almi,\"\nSo shouted his fierce lips, which sweeter hymns\nBecame not; and my guide address\'d him thus:\n\"O senseless spirit!  let thy horn for thee\nInterpret:  therewith vent thy rage, if rage\nOr other passion wring thee.  Search thy neck,\nThere shalt thou find the belt that binds it on.\nWild spirit!  lo, upon thy mighty breast\nWhere hangs the baldrick!\"  Then to me he spake:\n\"He doth accuse himself.  Nimrod is this,\nThrough whose ill counsel in the world no more\nOne tongue prevails.  But pass we on, nor waste\nOur words; for so each language is to him,\nAs his to others, understood by none.\"\n     Then to the leftward turning sped we forth,\nAnd at a sling\'s throw found another shade\nFar fiercer and more huge.  I cannot say\nWhat master hand had girt him; but he held\nBehind the right arm fetter\'d, and before\nThe other with a chain, that fasten\'d him\nFrom the neck down, and five times round his form\nApparent met the wreathed links.  \"This proud one\nWould of his strength against almighty Jove\nMake trial,\" said my guide; \"whence he is thus\nRequited: Ephialtes him they call.\nGreat was his prowess, when the giants brought\nFear on the gods:  those arms, ");strcat(expected_filecontent5, "re seal\'d on wax.  \"Fix not thy mind\nOn one place only,\" said the guide belov\'d,\nWho had me near him on that part where lies\nThe heart of man.  My sight forthwith I turn\'d\nAnd mark\'d, behind the virgin mother\'s form,\nUpon that side, where he, that mov\'d me, stood,\nAnother story graven on the rock.\n     I passed athwart the bard, and drew me near,\nThat it might stand more aptly for my view.\nThere in the self-same marble were engrav\'d\nThe cart and kine, drawing the sacred ark,\nThat from unbidden office awes mankind.\nBefore it came much people; and the whole\nParted in seven quires.  One sense cried, \"Nay,\"\nAnother, \"Yes, they sing.\"  Like doubt arose\nBetwixt the eye and smell, from the curl\'d fume\nOf incense breathing up the well-wrought toil.\nPreceding the blest vessel, onward came\nWith light dance leaping, girt in humble guise,\nSweet Israel\'s harper: in that hap he seem\'d\nLess and yet more than kingly.  Opposite,\nAt a great palace, from the lattice forth\nLook\'d Michol, like a lady full of scorn\nAnd sorrow.  To behold the tablet next,\nWhich at the hack of Michol whitely shone,\nI mov\'d me.  There was storied on the rock\nThe\' exalted glory of the Roman prince,\nWhose mighty worth mov\'d Gregory to earn\nHis mighty conquest, Trajan th\' Emperor.\nA widow at his bridle stood, attir\'d\nIn tears and mourning.  Round about them troop\'d\nFull throng of knights, and overhead in gold\nThe eagles floated, struggling with the wind.\nThe wretch appear\'d amid all these to say:\n\"Grant vengeance, sire!  for, woe beshrew this heart\nMy son is murder\'d.\"  He replying seem\'d;\n     \"Wait now till I return.\" And she, as one\nMade hasty by her grief; \"O sire, if thou\nDost not return?\"--\"Where I am, who then is,\nMay right thee.\"--\" What to thee is other\'s good,\nIf thou neglect thy own?\"--\"Now comfort thee,\"\nAt length he answers.  \"It beseemeth well\nMy duty be perform\'d, ere I move hence:\nSo justice wills; and pity bids me stay.\"\n     He, whose ken nothing new surveys, produc\'d\nThat visible speaking, new to us and strange\nThe like not found on earth.  Fondly I gaz\'d\nUpon those patterns of meek humbleness,\nShapes yet more precious for their artist\'s sake,\nWhen \"Lo,\" the poet whisper\'d, \"where this way\n(But slack their pace), a multitude advance.\nThese to the lofty steps shall guide us on.\"\n     Mine eyes, though bent on view of novel sights\nTheir lov\'d allurement, were not slow to turn.\n     Reader!  I would not that amaz\'d thou miss\nOf thy good purpose, hearing how just God\nDecrees our debts be cancel\'d.  Ponder not\nThe form of suff\'ring.  Think on what succeeds,\nThink that at worst beyond the mighty doom\nIt cannot pass.  \"Instructor,\" I began,\n\"What I see hither tending, bears no trace\nOf human semblance, nor of aught beside\nThat my foil\'");strcat(expected_filecontent6, "12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considera");strcat(expected_filecontent7, "ot.\"\n     Never was arrow from the cord dismiss\'d,\nThat ran its way so nimbly through the air,\nAs a small bark, that through the waves I spied\nToward us coming, under the sole sway\nOf one that ferried it, who cried aloud:\n\"Art thou arriv\'d, fell spirit?\"--\"Phlegyas, Phlegyas,\nThis time thou criest");


            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "EITHER");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "HIGH");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "CAPITAL.TX");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "BROKE.BIN");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "AS");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "MOMENT.BIN");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "CARE.TX");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file7 = file_open(volume, "FLOWERRU.TXT");
                    test_error(file7 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 3463, file0);
                test_error(size0 == 3463, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3463 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 3463);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 3463);
            
                size_t size1 = file_read(filecontent1, 1, 3365, file1);
                test_error(size1 == 3365, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3365 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 3365);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 3365);
            
                size_t size2 = file_read(filecontent2, 1, 1656, file2);
                test_error(size2 == 1656, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1656 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 1656);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 1656);
            
                size_t size3 = file_read(filecontent3, 1, 1536, file3);
                test_error(size3 == 1536, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1536 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 1536);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 1536);
            
                size_t size4 = file_read(filecontent4, 1, 2332, file4);
                test_error(size4 == 2332, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2332 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 2332);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 2332);
            
                size_t size5 = file_read(filecontent5, 1, 2752, file5);
                test_error(size5 == 2752, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2752 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 2752);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 2752);
            
                size_t size6 = file_read(filecontent6, 1, 89, file6);
                test_error(size6 == 89, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 89 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 89);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 89);
            
                size_t size7 = file_read(filecontent7, 1, 298, file7);
                test_error(size7 == 298, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 298 bajtów, a wczytała %lu", size7);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos7 = mem_find_first_difference(filecontent7, expected_filecontent7, 298);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos7 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos7, mem_get_byte(filecontent7, diff_pos7), mem_get_byte(expected_filecontent7, diff_pos7));
        
                onerror_compare_memory(expected_filecontent7, filecontent7, 298);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);
    free(filecontent7);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);
    file_close(file7);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2752, 1);
            char expected_filecontent[2753] = "";

            strcat(expected_filecontent, "re seal\'d on wax.  \"Fix not thy mind\nOn one place only,\" said the guide belov\'d,\nWho had me near him on that part where lies\nThe heart of man.  My sight forthwith I turn\'d\nAnd mark\'d, behind the virgin mother\'s form,\nUpon that side, where he, that mov\'d me, stood,\nAnother story graven on the rock.\n     I passed athwart the bard, and drew me near,\nThat it might stand more aptly for my view.\nThere in the self-same marble were engrav\'d\nThe cart and kine, drawing the sacred ark,\nThat from unbidden office awes mankind.\nBefore it came much people; and the whole\nParted in seven quires.  One sense cried, \"Nay,\"\nAnother, \"Yes, they sing.\"  Like doubt arose\nBetwixt the eye and smell, from the curl\'d fume\nOf incense breathing up the well-wrought toil.\nPreceding the blest vessel, onward came\nWith light dance leaping, girt in humble guise,\nSweet Israel\'s harper: in that hap he seem\'d\nLess and yet more than kingly.  Opposite,\nAt a great palace, from the lattice forth\nLook\'d Michol, like a lady full of scorn\nAnd sorrow.  To behold the tablet next,\nWhich at the hack of Michol whitely shone,\nI mov\'d me.  There was storied on the rock\nThe\' exalted glory of the Roman prince,\nWhose mighty worth mov\'d Gregory to earn\nHis mighty conquest, Trajan th\' Emperor.\nA widow at his bridle stood, attir\'d\nIn tears and mourning.  Round about them troop\'d\nFull throng of knights, and overhead in gold\nThe eagles floated, struggling with the wind.\nThe wretch appear\'d amid all these to say:\n\"Grant vengeance, sire!  for, woe beshrew this heart\nMy son is murder\'d.\"  He replying seem\'d;\n     \"Wait now till I return.\" And she, as one\nMade hasty by her grief; \"O sire, if thou\nDost not return?\"--\"Where I am, who then is,\nMay right thee.\"--\" What to thee is other\'s good,\nIf thou neglect thy own?\"--\"Now comfort thee,\"\nAt length he answers.  \"It beseemeth well\nMy duty be perform\'d, ere I move hence:\nSo justice wills; and pity bids me stay.\"\n     He, whose ken nothing new surveys, produc\'d\nThat visible speaking, new to us and strange\nThe like not found on earth.  Fondly I gaz\'d\nUpon those patterns of meek humbleness,\nShapes yet more precious for their artist\'s sake,\nWhen \"Lo,\" the poet whisper\'d, \"where this way\n(But slack their pace), a multitude advance.\nThese to the lofty steps shall guide us on.\"\n     Mine eyes, though bent on view of novel sights\nTheir lov\'d allurement, were not slow to turn.\n     Reader!  I would not that amaz\'d thou miss\nOf thy good purpose, hearing how just God\nDecrees our debts be cancel\'d.  Ponder not\nThe form of suff\'ring.  Think on what succeeds,\nThink that at worst beyond the mighty doom\nIt cannot pass.  \"Instructor,\" I began,\n\"What I see hither tending, bears no trace\nOf human semblance, nor of aught beside\nThat my foil\'");

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "MOMENT.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 2365, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2365] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2365], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3365, 1);
            char expected_filecontent[3366] = "";

            strcat(expected_filecontent, "u sayst:  but wherefore God this way\nFor our redemption chose, eludes my search.\n     \"Brother!  no eye of man not perfected,\nNor fully ripen\'d in the flame of love,\nMay fathom this decree.  It is a mark,\nIn sooth, much aim\'d at, and but little kenn\'d:\nAnd I will therefore show thee why such way\nWas worthiest.  The celestial love, that spume\nAll envying in its bounty, in itself\nWith such effulgence blazeth, as sends forth\nAll beauteous things eternal.  What distils\nImmediate thence, no end of being knows,\nBearing its seal immutably impress\'d.\nWhatever thence immediate falls, is free,\nFree wholly, uncontrollable by power\nOf each thing new: by such conformity\nMore grateful to its author, whose bright beams,\nThough all partake their shining, yet in those\nAre liveliest, which resemble him the most.\nThese tokens of pre-eminence on man\nLargely bestow\'d, if any of them fail,\nHe needs must forfeit his nobility,\nNo longer stainless.  Sin alone is that,\nWhich doth disfranchise him, and make unlike\nTo the chief good; for that its light in him\nIs darken\'d.  And to dignity thus lost\nIs no return; unless, where guilt makes void,\nHe for ill pleasure pay with equal pain.\nYour nature, which entirely in its seed\nTrangress\'d, from these distinctions fell, no less\nThan from its state in Paradise; nor means\nFound of recovery (search all methods out\nAs strickly as thou may) save one of these,\nThe only fords were left through which to wade,\nEither that God had of his courtesy\nReleas\'d him merely, or else man himself\nFor his own folly by himself aton\'d.\n     \"Fix now thine eye, intently as thou canst,\nOn th\' everlasting counsel, and explore,\nInstructed by my words, the dread abyss.\n     \"Man in himself had ever lack\'d the means\nOf satisfaction, for he could not stoop\nObeying, in humility so low,\nAs high he, disobeying, thought to soar:\nAnd for this reason he had vainly tried\nOut of his own sufficiency to pay\nThe rigid satisfaction.  Then behooved\nThat God should by his own ways lead him back\nUnto the life, from whence he fell, restor\'d:\nBy both his ways, I mean, or one alone.\nBut since the deed is ever priz\'d the more,\nThe more the doer\'s good intent appears,\nGoodness celestial, whose broad signature\nIs on the universe, of all its ways\nTo raise ye up, was fain to leave out none,\nNor aught so vast or so magnificent,\nEither for him who gave or who receiv\'d\nBetween the last night and the primal day,\nWas or can be.  For God more bounty show\'d.\nGiving himself to make man capable\nOf his return to life, than had the terms\nBeen mere and unconditional release.\nAnd for his justice, every method else\nWere all too scant, had not the Son of God\nHumbled himself to put on mortal flesh.\n     \"Now, to fulfil each wish of thine, remains\nI somewhat further to thy view unfold.\nThat thou mayst see as clearly as myself.\n     \"I see, thou sayst, the air, the fire I see,\nThe earth and water, and all things of them\nCompounded, to corruption turn, and soon\nDissolve.  Yet these were also things create,\nBecause, if what were told me, had been true\nThey from corruption had been therefore free.\n     \"The angels, O my brother!  and this clime\nWherein thou art, impassible and pure,\nI call created, as indeed they are\nIn their whole being.  But the elements,\nWhich thou hast nam\'d, and what of them is made,\nAre by created virtue\' inform\'d: create\nTheir substance");

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HIGH");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -668, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2697] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2697], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2752, 1);
            char expected_filecontent[2753] = "";

            strcat(expected_filecontent, "re seal\'d on wax.  \"Fix not thy mind\nOn one place only,\" said the guide belov\'d,\nWho had me near him on that part where lies\nThe heart of man.  My sight forthwith I turn\'d\nAnd mark\'d, behind the virgin mother\'s form,\nUpon that side, where he, that mov\'d me, stood,\nAnother story graven on the rock.\n     I passed athwart the bard, and drew me near,\nThat it might stand more aptly for my view.\nThere in the self-same marble were engrav\'d\nThe cart and kine, drawing the sacred ark,\nThat from unbidden office awes mankind.\nBefore it came much people; and the whole\nParted in seven quires.  One sense cried, \"Nay,\"\nAnother, \"Yes, they sing.\"  Like doubt arose\nBetwixt the eye and smell, from the curl\'d fume\nOf incense breathing up the well-wrought toil.\nPreceding the blest vessel, onward came\nWith light dance leaping, girt in humble guise,\nSweet Israel\'s harper: in that hap he seem\'d\nLess and yet more than kingly.  Opposite,\nAt a great palace, from the lattice forth\nLook\'d Michol, like a lady full of scorn\nAnd sorrow.  To behold the tablet next,\nWhich at the hack of Michol whitely shone,\nI mov\'d me.  There was storied on the rock\nThe\' exalted glory of the Roman prince,\nWhose mighty worth mov\'d Gregory to earn\nHis mighty conquest, Trajan th\' Emperor.\nA widow at his bridle stood, attir\'d\nIn tears and mourning.  Round about them troop\'d\nFull throng of knights, and overhead in gold\nThe eagles floated, struggling with the wind.\nThe wretch appear\'d amid all these to say:\n\"Grant vengeance, sire!  for, woe beshrew this heart\nMy son is murder\'d.\"  He replying seem\'d;\n     \"Wait now till I return.\" And she, as one\nMade hasty by her grief; \"O sire, if thou\nDost not return?\"--\"Where I am, who then is,\nMay right thee.\"--\" What to thee is other\'s good,\nIf thou neglect thy own?\"--\"Now comfort thee,\"\nAt length he answers.  \"It beseemeth well\nMy duty be perform\'d, ere I move hence:\nSo justice wills; and pity bids me stay.\"\n     He, whose ken nothing new surveys, produc\'d\nThat visible speaking, new to us and strange\nThe like not found on earth.  Fondly I gaz\'d\nUpon those patterns of meek humbleness,\nShapes yet more precious for their artist\'s sake,\nWhen \"Lo,\" the poet whisper\'d, \"where this way\n(But slack their pace), a multitude advance.\nThese to the lofty steps shall guide us on.\"\n     Mine eyes, though bent on view of novel sights\nTheir lov\'d allurement, were not slow to turn.\n     Reader!  I would not that amaz\'d thou miss\nOf thy good purpose, hearing how just God\nDecrees our debts be cancel\'d.  Ponder not\nThe form of suff\'ring.  Think on what succeeds,\nThink that at worst beyond the mighty doom\nIt cannot pass.  \"Instructor,\" I began,\n\"What I see hither tending, bears no trace\nOf human semblance, nor of aught beside\nThat my foil\'");

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "MOMENT.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 901, SEEK_SET);
            file_seek(file, 487, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1388] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1388], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MATTER");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MATTER) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BROAD");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BROAD) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BIT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BIT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "COAST");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (COAST) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MUCH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MUCH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SETTLE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SETTLE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "RUB");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (RUB) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WAVEENEM");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WAVEENEM) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "INCH.TX");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie INCH.TX, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "INCH.TX");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "EITHER");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[16] = { "EITHER", "HIGH", "CAPITAL.TX", "BROKE.BIN", "AS", "MOMENT.BIN", "CARE.TX", "FLOWERRU.TXT", "MATTER", "BROAD", "BIT", "COAST", "MUCH", "SETTLE", "RUB", "WAVEENEM" };
            int found_names[16] = { 0 };

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 16; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 16; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "EITHER");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HIGH");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "CAPITAL.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BROKE.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 54: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "AS");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 55: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST55(void)
{
    // informacje o teście
    test_start(55, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "MOMENT.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 56: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST56(void)
{
    // informacje o teście
    test_start(56, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "CARE.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 57: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST57(void)
{
    // informacje o teście
    test_start(57, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "FLOWERRU.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 58: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST58(void)
{
    // informacje o teście
    test_start(58, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("pass_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "foot");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
          UTEST22, // Sprawdzanie poprawności działania funkcji file_read
           UTEST23, // Sprawdzanie poprawności działania funkcji file_read
           UTEST24, // Sprawdzanie poprawności działania funkcji file_read
           UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
           UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
          UTEST29, // Sprawdzanie poprawności działania funkcji file_read
           UTEST30, // Sprawdzanie poprawności działania funkcji file_read
            UTEST31, // Sprawdzanie poprawności działania funkcji file_read
            UTEST32, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST33, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST34, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_open
            UTEST41, // Sprawdzanie poprawności działania funkcji file_open
            UTEST42, // Sprawdzanie poprawności działania funkcji file_open
            UTEST43, // Sprawdzanie poprawności działania funkcji file_open
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji file_read
            UTEST47, // Sprawdzanie poprawności działania funkcji file_close
            UTEST48, // Sprawdzanie poprawności działania funkcji file_read
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST54, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST55, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST56, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST57, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST58, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(58); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}