#define tamanho 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct aluno {
    float media;
} ALUNO;

void ordena (ALUNO turma[], int tam) {
    int i, foraOrdem , jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < tam-1 ; i++) {
        if (turma[i].media > turma[i+1].media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados ++;
    } while ( foraOrdem );
}

void main(){
    srand(time(NULL));
    ALUNO turma[tamanho];
    printf("Desordenado:\n");
    for (int i = 0; i < tamanho; i++){
        float media = ((float)rand()/(float)RAND_MAX) * 6 + 4;
        printf("%.2f\n", media);
        turma[i].media = media;
    }
    printf("\nOrdenado:\n");
    ordena(turma, tamanho);
    for (int i = 0; i < tamanho; i++){
        printf("%.2f\n", turma[i].media);
    }
}