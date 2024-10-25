#include <stdio.h>

char amet_cevap[256] = "\n\
1. Ezbırçime\n\
2. belə vəziyyət içine soxum\n\
";

char demirtas_cevap[256] = "\n\
1. Merhaba\n\
2. Naber\n\
";

char ocalan_cevap[256] = "\n\
1. am_cuk_yarrak_tassak_31\n\
2. zencigot\n\
";

void answer(char* name) {
    	if (strcmp(name, "Amet") == 0 || strcmp(name, "amet") == 0) {
    	char *answer1 = "%s : Sikismek istiyorum", name;
    	char *answer2 = "%s : Zencigot severim", name;
    	char *answer3 = "%s : Essek_siker_31", name;
    	char *answer4 = "%s : kurt_ami_sever_31", name;
    	char *arr[50] = {(answer1[rand()%5]), (answer2[rand() % 5]), (answer3[rand() % 5]), (answer4[rand() % 5])};
	printf("%s", arr);
	sikis();
    }
	else {
	     /*Other people will be added*/
	} 
}
