#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int n;

void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int aleatorio = rand() % 100 + 1; // resto de 5 faz com que numeros variem entre 0 e 99, somar 1 faz com que varie entre 1 e 100.
    printf("Eu pensarei em um número entre 1 e 100, faça o mesmo e veja se pensamos igual!.\n");
    printf("Insira um número de 1 a 100: ");
    scanf("%d", &n);
    printf("Eu pensei no número %d, você pensou no número %d.", aleatorio, n);
}
