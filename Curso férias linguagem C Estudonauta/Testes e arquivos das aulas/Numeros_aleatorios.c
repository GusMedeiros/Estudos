#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int n;

void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int aleatorio = rand() % 5 + 1;
    printf("Eu pensarei em um n�mero entre 1 e 5, fa�a o mesmo e veja se pensamos igual!.\n");
    printf("Insira um n�mero de 1 a 5: ");
    scanf("%d", &n);
    printf("Eu pensei no n�mero %d, voc� pensou no n�mero %d.", aleatorio, n);

}