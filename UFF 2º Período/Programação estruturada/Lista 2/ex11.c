#include <math.h>
#include <stdio.h>
#include <locale.h>
void main()
{
    setlocale(LC_ALL, "Portuguese");
    int base, expoente;
    printf("Insira a base da potência: ");
    scanf("%d", &base);
    printf("Insira o expoente da potência: ");
    fflush(stdin);
    scanf("%d", &expoente);

    printf("O resultado da potência %d^%d é %d", base, expoente, (int)pow(base, expoente));
}