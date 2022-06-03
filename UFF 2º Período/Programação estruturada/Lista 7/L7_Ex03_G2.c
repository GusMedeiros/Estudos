#include <stdio.h>
#include <stdlib.h>
int vetor(int tamanho){
    int i;
    int *v = (int*) malloc(tamanho*sizeof(int));
    if (v==NULL){exit(1);}
    for (i=0;i<tamanho;i++){
        v[i] =5*i;
    }
    for(i=0;i<tamanho;i++){
        printf("%d \n", v[i]);
    }
    return 0;
}

int main(){
    printf("Insira o tamanho do vetor ");
    int tamanho;
    scanf("%d", &tamanho);
    vetor(tamanho);
}
