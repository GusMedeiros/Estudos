#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um n�mero qualquer: ");
    int numero;
    fflush(stdin);
    scanf("%d", &numero);
    printf("O n�mero que voc� digitou � %s!", numero%2==0?"PAR":"�MPAR");

}