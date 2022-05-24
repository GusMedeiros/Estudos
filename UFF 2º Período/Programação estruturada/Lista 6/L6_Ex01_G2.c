#include <stdio.h>
#include <stdlib.h>

float* acima_da_media(int n, float *vet, int *tam){
    float media = 0;
    float* vet_resposta;
    int i, count=0, j;

    for(i=0;i<n;i++){ // Calcula media
        media += vet[i];
    }
    media /= n;
    for(i=0;i<n;i++){ // Conta os acima da media
        if(vet[i]>media){
            count++;
        }
    }
    vet_resposta = (float *) malloc(count*sizeof(float));
    if (vet_resposta==NULL){
        return NULL;
    }
    j=0;
    for(i=0;i<n;i++){
        if(vet[i]>media){
            vet_resposta[j] = vet[i];
            j++;
        }
    }
    *tam = count;
    return vet_resposta;
}

int main(void){
    float v[] = {5.5, 3.2, 2.5, 9.4, 7.5, 4.1, 5.4, 8.0, 6.9};
    float *v_acima_media;
    int *tam, i;

    tam = (int *) malloc(sizeof(int));

    v_acima_media = acima_da_media(9, v, tam);
    
    for(i=0;i<(*tam);i++){
        printf(" %f", v_acima_media[i]);
    }

    free(v_acima_media);
    free(tam);
}