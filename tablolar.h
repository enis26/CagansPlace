#include <stdio.h>
#include <string.h>

char icecektablosu[512] = "                     \n\
        İçecekler        |          Alkol       \n\
-------------------------|-----------------------\n\
1 - Alp Cola : 30TL       | 4 - Bira : 100TL       \n\
2 - Enginar Suyu : 70TL  | 5 - Şarap : 500TL      \n\
3 - Havuç Suyu : 40TL    | 6 - Şampanya : 350TL   \n\
";

char yiyecektablosu[512] = "                          \n\
    Ana Yemekler        |   Diğer yiyecekler           \n\
------------------------|--------------------           \n\
1 - Kurufasulye : 80TL  | 4 - Hıyar(adanali olan) : 45TL \n\
2 - Izgara Köfte : 250TL | 5 - Domates : 65TL               \n\
3 - Adana Kebap : 150TL  | 6 - Enginar (Soyulmus) : 600TL               \n\
";
char oyuntablosu[512] = "\n\
                 Oyunlar\n\
-----------------------------------------\n\
1 - Bowling : 200  |   2 - Bilardo : 150TL\n\
";

int yiyecek_fiyat(int no) {
    switch(no) {
        case 1:
            return(10);
        case 2:
            return(25);
        case 3:
            return(20);
        case 4:
            return(20);
        case 5:
            return(5);
        case 6:
            return(30);
        default:
            printf("siktir git amerikadamiyiz oc\n");
            exit(1);
    }
}

int icecek_fiyat(int no) {
    switch(no) {
        case 1:
            return(5);
        case 2:
            return(10);
        case 3:
            return(15);
        case 4:
            return(20);
        case 5:
            return(30);
        case 6:
            return(50);
        default:
            printf("haram lan o - Mashiro");
            return 0;
    }
}

int oyun_fiyat(int no) {
    switch(no) {
        case 1:
            return(10);
        case 2:
            return(20);
        default:
            printf("hepsi amerikanin oyunu - mert usta");
            return 0;
    }
}
