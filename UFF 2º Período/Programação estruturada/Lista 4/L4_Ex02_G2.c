#include <stdio.h>

int busca_elemento(int tam, int *vet, int elem){
    int i;
    for (i=0; i<tam;i++){
        if (elem==vet[i]){
            return 1;
        }
    }
    return 0;
}

int main() {
    int i, j, k=0, r[5], s[10], x[5], res_busca;

    printf("Vetor r \n");
    for (i=0; i<5; i++){
        printf("Digite um valor: ");
        scanf("%d", &r[i]);
    }
    printf("\n Vetor s \n");
    for (i=0; i<10; i++){
        printf("Digite um valor: ");
        scanf("%d", &s[i]);
    }

    for (i=0; i<5; i++){
        for (j=0; j<10; j++){
            if (r[i] == s[j]){
                res_busca=busca_elemento(k,x,r[i]);
                if (res_busca==0){
                    x[k]=r[i];
                    k++;
                }
            }
        }
    }

    printf("\nVetor X: \n");
    for (i=0; i<k; i++)
        printf("%d ", x[i]);


    return 0;
}
