#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    printf("Vou pensar em um n�mero entre 1 e 5. Tente adivinhar!\n");
    printf("Qual � o seu palpite? ");
    fflush(stdin);
    int numero;
    scanf("%d", &numero);
    fflush(stdin);
    int aleatorio = rand() %5 + 1;
    printf("Eu pensei no n�mero %d e voc� pensou no %d.", aleatorio, numero);
}
