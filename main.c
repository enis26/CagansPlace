#include <stdio.h>
#include <string.h>
#include "functions.c"
#include <stdlib.h>

#define RED(string) "\x1b[31m" string "\x1b[0m"

char* cagan = "					\n\
 ▄████▄   ▄▄▄        ▄████  ▄▄▄       ███▄    █ \n\
▒██▀ ▀█  ▒████▄     ██▒ ▀█▒▒████▄     ██ ▀█   █ \n\
▒▓█    ▄ ▒██  ▀█▄  ▒██░▄▄▄░▒██  ▀█▄  ▓██  ▀█ ██▒\n\
▒▓▓▄ ▄██▒░██▄▄▄▄██ ░▓█  ██▓░██▄▄▄▄██ ▓██▒  ▐▌██▒\n\
▒ ▓███▀ ░ ▓█   ▓██▒░▒▓███▀▒ ▓█   ▓██▒▒██░   ▓██░\n\
░ ░▒ ▒  ░ ▒▒   ▓▒█░ ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ▒ ▒ \n\
  ░  ▒     ▒   ▒▒ ░  ░   ░   ▒   ▒▒ ░░ ░░   ░ ▒░\n\
░          ░   ▒   ░ ░   ░   ░   ▒      ░   ░ ░ \n\
░ ░            ░  ░      ░       ░  ░         ░ \n\
░                                               \n\
						\n\
";
char isim[256];
char cinsiyet[256];
void login();
void giris();
char gir[256];
char* config = "$HOME/CagansPlace/character";

void main() {
	printf(RED("%s"), cagan);
    giris();
}

bool character_exist(const char *filename) {
    FILE *fp = fopen(filename, "r");
    bool is_exists = false;
    if (fp != NULL) {
        is_exists = true;
        fclose(fp);
    }
    return is_exists;
}

void login() {
    if (character_exist(config)) {
        hosgeldiniz(isim, cinsiyet);
    }
    else {
    system("mkdir $HOME/CagansPlace/ && touch $HOME/CagansPlace/character");
	printf("Cagan'ın mekanı! Adınız nedir? : ");
	scanf("%s", isim);
	printf("Cinsiyet? (Bay/Bayan) : ");
	scanf("%s", cinsiyet);

	hosgeldiniz(isim, cinsiyet);
    }
}

void giris() {

    printf("Karakterimiz girişi gördüğü zaman girip girmemek konusunda kararsız kaldı. Tabela kanla yazılmıştı. Ama saat iyice geç olmuştu ve bir an önce karar vermesi gerekiyordu.");
    
    while(strcmp(gir, "girme") != 0 || strcmp(gir, "Girme") != 0) {
        printf("\nGentoo yu sikecek misin(Sik/Sikme) : ");
        scanf("%s", gir);

        if(strcmp(gir, "sik") == 0 || strcmp(gir, "Sik") == 0) {
            login();
        }
        else if (strcmp(gir, "sikme") == 0 || strcmp(gir, "Sikme") == 0) {
            printf("30 gündür gentoo derleyerek sellfuck yaptı".\n");
            break;
        }
        else {
            printf("Lütfen geçerli bir şey giriniz!\n");
            continue;
        }
    }
}
