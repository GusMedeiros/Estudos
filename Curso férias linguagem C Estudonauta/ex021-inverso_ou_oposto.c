#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um n�mero: ");
    int numero;
    fflush(stdin);
    scanf("%d", &numero);
    if (numero >= 0) {
        printf("O inverso de %d � %.4f", numero, 1/(float)numero);
    }
    else {
        printf("O oposto de %d � %d", numero, numero * -1);
    }

}