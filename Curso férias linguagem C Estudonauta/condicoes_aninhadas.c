#include<stdio.h>

void main() {
    printf("Primeiro valor: ");
    int n1, n2;
    fflush(stdin);
    scanf("%d", &n1);
    printf("Segundo valor: ");
    fflush(stdin);
    scanf("%d", &n2);
    if (n1 > n2) {
        printf("maior = %d", n1);
    } 
    else {
        if (n1 < n2) {
            printf("maior = %d", n2);
        }
        else{
            printf("VALORES IGUAIS");
        }
    }
}