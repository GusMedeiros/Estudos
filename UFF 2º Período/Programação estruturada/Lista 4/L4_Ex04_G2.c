#include <stdio.h>
int testa_PA(int n, int* v);

int main()
{
    int tam, i;
    printf("Digite o comprimento do vetor (podendo ser maior ou igual a 3): ");
    scanf("%d", &tam);
    int vet[tam];
    
    for(i = 0; i < tam; i++){
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &vet[i]);
    } 
    
    printf("%d", testa_PA(tam,vet));

    return 0;
}

int testa_PA(int n, int* vet){
    int i, k, k_old;
    for(i = 1; i < n; i++){
        k = vet[i]-vet[i-1];
        if(k_old != k && i > 1){
            k = 0;
            break;
        }
        k_old = k;
    }
    return k;
}

    