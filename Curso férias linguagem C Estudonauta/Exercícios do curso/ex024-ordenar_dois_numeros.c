#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Me diga dois n�meros e eu colocarei\n");
    printf("os dois em ordem crescente.\n\n");
    printf("Primeiro n�mero: ");
    int n1, n2;
    fflush(stdin);
    scanf("%d", &n1);
    printf("Segundo n�mero: ");
    fflush(stdin);
    scanf("%d", &n2);
    if (n1 > n2) {
        printf("Ordenado fica: %d %d", n2, n1);
    }
    else if (n2 > n1) {
        printf("Ordenado fica: %d %d", n1, n2);
    }
    else {
        printf("%d e %d s�o IGUAIS", n1, n2);
    }
}