#include <stdio.h>
#include <locale.h>
#include <string.h>
void main(){
    setlocale(LC_ALL,"Portuguese");
    printf("Insira a sigla de um estado: ");
    char uf[2];
    fflush(stdin);
    gets(uf);
    printf("Quem nasce em %s � ", uf);
    if (strcmp(uf, "RJ") == 0) {
        printf("fluminense.");
    }
    else if (strcmp(uf, "SP") == 0) {
        printf("paulista.");
    }
    else if (strcmp(uf, "MG") == 0) {
        printf("mineiro.");
    }
    else if (strcmp(uf, "SC") == 0) {
        printf("catarinense");
    }
    else {
        printf("... hmmm...\nainda n�o sei a resposta :(");
    }
}