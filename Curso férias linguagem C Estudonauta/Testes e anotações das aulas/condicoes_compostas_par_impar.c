#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    int numero;
    printf("Insira um n�mero inteiro e lhe direi se � par ou impar: ");
    fflush(stdin);
    scanf("%d", &numero);
    if (numero % 2 == 0) printf("O n�mero � par");
    else printf("O n�mero � impar");
}