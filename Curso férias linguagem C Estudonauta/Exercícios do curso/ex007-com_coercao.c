#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um n�mero: ");
    int numero, dobro;
    float terca_parte;

    fflush(stdin);
    scanf("%d", &numero);
    fflush(stdin);

    dobro = numero * 2;
    terca_parte = (float)numero / 3;
    printf("Analisando o n�mero %d seu dobro � %d e sua ter�a parte � de %.2f.", numero, dobro, terca_parte);
}
