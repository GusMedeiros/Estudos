float media (char* mat, char* nome_arquivo);

#include <stdlib.h>
#include <stdio.h>

float media (char* mat, char* nome_arquivo){
    char matricula[10];
    float nota1, nota2, nota3;
    FILE *f = fopen(nome_arquivo, "r");
    if (f = NULL) {
        printf("ERRO");
        exit(-1.0);
    }
    while (fscanf(f, "%s %f %f %f", matricula, &nota1, &nota2, &nota3)!= 0){
        if (!strcmp(matricula, mat)) {
            float media = (nota1 + nota2 + nota3)/3.0 ;
            return media;
        }
    }
    return -1.0;
}