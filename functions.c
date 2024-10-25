#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tablolar.h"
#include <ctype.h>
#include "oyun.c"
#include <stdbool.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define YELLOW(string) "\x1b[33m" string "\x1b[0m"

char cikis[256];
void icerigir();
void hayirgirme();
void yemek();
void icecek();
void oyun();
void ps1();
void konus();
void konus_ahmet();
void konus_john();
void konus_mehmet();

char istek[256];
static int yiyecek_istek;
static int icecek_istek;
static int oyun_istek;
int ilk_tanisma = 1;

typedef struct {
    int money;
    char* Name;
    char* Cinsiyet;
} user;

typedef struct { char *key; int val; } t_symstruct;

user primary;

#include "answers.h"

void hosgeldiniz(char* name, char* cinsiyet) {
	printf(GREEN("\
##################################\n\
# ")YELLOW("Cagan'ın mekanına hoş geldiniz ")GREEN("#\n\
##################################"));
    primary.Name = name;
    primary.Cinsiyet = cinsiyet;
    primary.money = 100;

    icerigir(primary.Name, primary.money, primary.Cinsiyet);
}

void icerigir(char* name, int money, char* cinsiyet) {
	if(ilk_tanisma == 1) {
        printf("\n[Cagan]: Merhaba %s %s. Size nasıl yardımcı olabilirim? (İçecek/Yemek/Oyun)\n", cinsiyet, name);
        ilk_tanisma = 0;
    }
    else {
        printf("[Cagan]: Size nasıl yardımcı olabilirim ?\n");
    }
    ps1(name, money);
	scanf("%s", istek);

	if (strcmp(istek, "Yemek") == 0 || strcmp(istek, "yemek") == 0) {
		yemek(name, money);
	}
	else if (strcmp(istek, "İçecek") == 0 || strcmp(istek, "içecek") == 0) {
		icecek(name, money);
	}
	else if (strcmp(istek, "oyun") == 0 || strcmp(istek, "Oyun") == 0) {
		oyun(primary.Name, primary.money);
	}
    else {
        printf("Böyle bir seçenek yok!");
        icerigir(primary.Name, primary.money, primary.Cinsiyet);
    }
}

void hayirgirme() {
	printf("Bir dahaki sefere görüşmek üzere.\n");
	exit(1);
}

void yemek(char* name, int money) {
        while(strcmp(istek, "çık") != 0 || strcmp(istek, "Çık") != 0) {
	    printf("[Cagan]: Tabiki ne istersiniz ?");
        printf("%s", yiyecektablosu);
        ps1(name, money);
        scanf("%d", &yiyecek_istek);
        if(money >= yiyecek_fiyat(yiyecek_istek)) {
            money -= yiyecek_fiyat(yiyecek_istek);
        }
        else {
            printf("Yeterli paranız yok!");
            icerigir(name, money, primary.Cinsiyet);
        }
        printf("[Cagan]: Hemen geliyor. Başka bir istediğiniz var mıdır?(Menu/Oyun/Yemek/İçecek/Çık)\n");
        ps1(name, money);
        scanf("%s", istek);

        if (strcmp(istek, "yemek") == 0 || strcmp(istek, "Yemek") == 0) {
            yemek(name, money);
        }
        else if (strcmp(istek, "oyun") == 0 || strcmp(istek, "Oyun") == 0) {
            oyun(primary.Name, primary.money);
        }
        else if (strcmp(istek, "içecek") == 0 || strcmp(istek, "İçecek") == 0) {
            icecek(name, money);
        }
        else if (strcmp(istek, "menu") == 0 || strcmp(istek, "Menu") == 0) {
            icerigir(name, money, primary.Cinsiyet);
        }
        else if (strcmp(istek, "Çık") == 0 || strcmp(istek, "çık") == 0) {
            hayirgirme();
            break;
        }
        else {
            continue;
        }
    }
}

void icecek(char* name, int money) {
    while(istek != "evet") {
        printf("[Cagan]: ne istiyon yaragim ?");
    printf("%s", icecektablosu);
    ps1(name, money);
    scanf("%d", &icecek_istek);
    if(money >= icecek_fiyat(icecek_istek)) {
        money -= icecek_fiyat(icecek_istek);
    }
    else {
        printf("amk fukarasi siktirgit");
        icerigir(name, money, primary.Cinsiyet);
    }
    printf("[Cagan]: Hemen geliyor. Başka bir istediğiniz var mıdır?(Menu/Oyun/Yemek/İçecek)\n");
    ps1(name, money);
    scanf("%s", istek);

    if (strcmp(istek, "yemek") == 0 || strcmp(istek, "Yemek") == 0) {
        yemek(name, money);
    }
    else if (strcmp(istek, "oyun") == 0 || strcmp(istek, "Oyun") == 0) {
        oyun(name, money);
    }
    else if (strcmp(istek, "içecek") == 0 || strcmp(istek, "İçecek") == 0) {
        icecek(name, money);
    }
    else if (strcmp(istek, "menu") == 0 || strcmp(istek, "Menu") == 0) {
        icerigir(name, money, primary.Cinsiyet);
    }
    else if (strcmp(istek, "Çık") == 0 || strcmp(istek, "çık") == 0) {
        hayirgirme();
    }
    else {
        printf("Böyle bir seçenek yok!\n");
        icerigir(name, money, primary.Cinsiyet);
    }
    }
}

void oyun(char* name, int money) {
    printf("Hangi oyunu oynamak istersiniz? ");
    printf("%s", oyuntablosu);
    ps1(name, money);
    scanf("%d", &oyun_istek);
    if (money >= oyun_fiyat(oyun_istek)) {
        money -= oyun_fiyat(oyun_istek);
        switch(oyun_istek) {
            case 1:
                /*bowling(name, money);*/
            case 2:
                /*bilardo(name, money);*/
            case 3:
                /*oyun3();*/
        }
    }
    else {
        printf("Yeterli paranız yok!");
        icerigir(primary.Name, primary.money, primary.Cinsiyet);
    }

    printf("Başka ne yapmak istersiniz?(Yemek/Menu/Oyun/İçecek)\n");
    ps1(name, money);
    scanf("%s", istek);

    if (strcmp(istek, "yemek") == 0 || strcmp(istek, "Yemek") == 0) {
        yemek(name, money);
    }
    else if (strcmp(istek, "oyun") == 0 || strcmp(istek, "Oyun") == 0) {
        oyun(name, money);
    }
    else if (strcmp(istek, "içecek") == 0 || strcmp(istek, "İçecek") == 0) {
        icecek(name, money);
    }
    else if (strcmp(istek, "menu") == 0 || strcmp(istek, "Menu") == 0) {
        icerigir(name, money, primary.Cinsiyet);
    }
    else if (strcmp(istek, "Çık") == 0 || strcmp(istek, "çık") == 0) {
        hayirgirme();
    }
    else {
        printf("Böyle bir seçenek yok!");
        icerigir(name, money, primary.Cinsiyet);
    }
}

void ps1(char* name, int money) {
    printf("["GREEN("$%d")"] %s : ", money, name);
}

void konus(char* name, int money) {
    printf("Kiminle konuşmak isterseniz:\n\
            1. Selahattin D.\n\
	    2. Murat K.\n\
            3. Abdullah O.\n\
	    4. Fetullah G.\n\
            5. Berkin E.");
    ps1(name, money);
    char who[256];
    scanf("%s", who);
    answer(who);
}
