#include <math.h>
#include <stdio.h>
#include <locale.h>
void main()
{
    setlocale(LC_ALL, "Portuguese");
    int base, expoente;
    printf("Insira a base da pot�ncia: ");
    scanf("%d", &base);
    printf("Insira o expoente da pot�ncia: ");
    fflush(stdin);
    scanf("%d", &expoente);

    printf("O resultado da pot�ncia %d^%d � %d", base, expoente, (int)pow(base, expoente));
}