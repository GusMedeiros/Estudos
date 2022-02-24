#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um número qualquer: ");
    int numero;
    fflush(stdin);
    scanf("%d", &numero);
    printf("O número que você digitou é %s!", numero%2==0?"PAR":"ÍMPAR");

}