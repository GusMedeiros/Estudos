#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int n;

void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int aleatorio = rand() % 5 + 1;
    printf("Eu pensarei em um número entre 1 e 5, faça o mesmo e veja se pensamos igual!.\n");
    printf("Insira um número de 1 a 5: ");
    scanf("%d", &n);
    printf("Eu pensei no número %d, você pensou no número %d.", aleatorio, n);

}