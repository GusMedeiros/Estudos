#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int n;

void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int aleatorio = rand() % 100 + 1; // resto de 5 faz com que numeros variem entre 0 e 99, somar 1 faz com que varie entre 1 e 100.
    printf("Eu pensarei em um n�mero entre 1 e 100, fa�a o mesmo e veja se pensamos igual!.\n");
    printf("Insira um n�mero de 1 a 100: ");
    scanf("%d", &n);
    printf("Eu pensei no n�mero %d, voc� pensou no n�mero %d.", aleatorio, n);
}
