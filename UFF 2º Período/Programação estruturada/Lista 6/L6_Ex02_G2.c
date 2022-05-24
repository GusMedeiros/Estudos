#include <stdio.h>
#include <stdlib.h>

int* aprovados(int n, int *mat, float *notas, int *tam){
    float nota_para_passar = 5.0;
    int *aprovados, i, count=0, j;

    for(i=0;i<n;i++){ // Conta os aprovados (nota>=5.0)
        if(notas[i]>=nota_para_passar){
            count++;
        }
    }
    aprovados = (int *) malloc(count*sizeof(int));
    if(aprovados==NULL){
        return NULL;
    }

    j=0;
    for(i=0;i<n;i++){
        if(notas[i]>=nota_para_passar){
            aprovados[j] = mat[i];
            j++;
        }
    }
    *tam = count;

    return aprovados;
}

int main(void){
    int turma[] = {10, 11, 12, 13, 14};
    float notas[] = {5.0, 3.2, 2.5, 9.4, 7.5};
    int *alunos_aprovados, *tam, i;

    tam = (int *) malloc(sizeof(int));

    alunos_aprovados = aprovados(5, turma, notas, tam);

    for(i=0;i<(*tam);i++){
        printf(" %d", alunos_aprovados[i]);
    }

    free(alunos_aprovados);
    free(tam);
}