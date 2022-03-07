#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    int numero;
    printf("Insira um número inteiro e lhe direi se é par ou impar: ");
    fflush(stdin);
    scanf("%d", &numero);
    if (numero % 2 == 0) printf("O número é par");
    else printf("O número é impar");
}