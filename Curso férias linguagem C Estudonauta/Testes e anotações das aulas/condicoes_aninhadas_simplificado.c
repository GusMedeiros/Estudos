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
        printf("maior = n1 = %d", n1);
    }
    else if (n1 < n2) {
            printf("maior = n2 = %d", n2);
        }
        else {
            printf("VALORES IGUAIS");
        }
}