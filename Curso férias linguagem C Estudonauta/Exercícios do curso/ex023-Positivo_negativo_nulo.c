#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Me diga um n�mero e eu te direi se\n");
    printf("ele � POSITIVO, NEGATIVO ou NULO.\n\n");
    printf("Digite um n�mero: ");
    float numero;
    fflush(stdin);
    scanf("%f", &numero);
    if (numero == 0) {
        printf("%.2f � nulo", numero);
    }
    else if (numero > 0) {
        printf("%.2f � positivo", numero);
    }
    else {
        printf("%.2f � negativo", numero);
    }
}