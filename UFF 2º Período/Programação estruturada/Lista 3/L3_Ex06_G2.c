#include <stdio.h>


int maiores(int n, int *vet, int x){
    int i, qnt=0;
    for (i=0; i<n; i++){
        if (vet[i]>x)
            qnt+=1;
    }
    return qnt;
}

int main() {
    int i, n, *vet, x;

    printf("Digite o tamanho do vetor:");
    scanf("%d",&n);

    vet = (float *) malloc(n*sizeof(float));
    if (vet==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }

    for (i=0; i<n; i++){
        printf("Insira um numero no vetor: ");
        scanf("%d", &vet[i]);
    }

    printf("Digite um numero X: ");
    scanf("%d", &x);

    printf("Quantidade de numeros maiores que valor %d: %d \n",x, maiores(n, vet, x));

    free(vet);

    return 0;
}

