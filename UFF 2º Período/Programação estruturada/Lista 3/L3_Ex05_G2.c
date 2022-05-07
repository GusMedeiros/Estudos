#include <stdio.h>


float max_vet(int n, float *vet){
    int i;
    float maior;
    maior=vet[0];

    for (i=1; i<n; i++){
        if (vet[i]>maior)
            maior=vet[i];
    }
    return maior;
}

int main() {
    int i, n;
    float *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    vet = (float *) malloc(n*sizeof(float));
    if (vet==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }

    for (i=0; i<n; i++){
        printf("Digite o numero: ");
        scanf("%f", &vet[i]);
    }

    printf("Maior valor: %.2f \n", max_vet(n, vet));

    free(vet);
    return 0;
}
