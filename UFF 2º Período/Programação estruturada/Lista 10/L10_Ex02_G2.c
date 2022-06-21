#include <stdio.h>
#include <stdlib.h>

float busca (char* arquivo, char* matricula);

float busca (char* arquivo, char* matricula){
    FILE *f = fopen(arquivo, "r");
    if (f == NULL){
        printf("ERRO\n");
        
    }
    char matr[10]; int cr;
    if (f == NULL) exit(-1);
    while (fscanf(f, "%s %f", matr, &cr) != 0){
        if (!strcmp(matr, matricula)) {
            fclose(arquivo);
            return cr;
        }
    }
    fclose(arquivo);
    return -1;
}
