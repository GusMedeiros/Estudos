#include <stdio.h>
#include <locale.h>
void main()
{
    int a = 1, b = 2, c = 3, d = 4;
    float e = 0.1, f = 0.2, g = 0.3, h = 0.4;
    char v[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int x = 99;

    int *ponteiro = &a;
    ponteiro++;
    setlocale(LC_ALL, "Portuguese");
    printf("Valor apontado no endere�o %x = %d\n",ponteiro, *(ponteiro));
    if (ponteiro == &a || ponteiro == &b || ponteiro == &c || ponteiro == &d)
    {
        printf("Endere�o coincide com vari�vel. Ela � do tipo Int.");
        x = 1;
    }
    if (ponteiro == &e || ponteiro == &f || ponteiro == &g || ponteiro == &h)
    {
        printf("Endere�o coincide com uma vari�vel. Ela � do tipo Float.");
        x = 1;
    }
    for (int i = 0;(i <= 10); i++)
    {
        if (ponteiro == &v[i])
        printf("Endere�o coincide com uma vari�vel. Ela � do tipo CHAR.");
        x = 1;
    }
    if (x == 1)
        printf("O endere�o nao coincidiu com uma vari�vel.");
}