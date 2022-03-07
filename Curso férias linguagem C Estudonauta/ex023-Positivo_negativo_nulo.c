#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Me diga um número e eu te direi se\n");
    printf("ele é POSITIVO, NEGATIVO ou NULO.\n\n");
    printf("Digite um número: ");
    float numero;
    fflush(stdin);
    scanf("%f", &numero);
    if (numero == 0) {
        printf("%.2f é nulo", numero);
    }
    else if (numero > 0) {
        printf("%.2f é positivo", numero);
    }
    else {
        printf("%.2f é negativo", numero);
    }
}