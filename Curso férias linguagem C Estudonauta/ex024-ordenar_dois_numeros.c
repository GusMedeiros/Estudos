#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Me diga dois números e eu colocarei\n");
    printf("os dois em ordem crescente.\n\n");
    printf("Primeiro número: ");
    int n1, n2;
    fflush(stdin);
    scanf("%d", &n1);
    printf("Segundo número: ");
    fflush(stdin);
    scanf("%d", &n2);
    if (n1 > n2) {
        printf("Ordenado fica: %d %d", n2, n1);
    }
    else if (n2 > n1) {
        printf("Ordenado fica: %d %d", n1, n2);
    }
    else {
        printf("%d e %d são IGUAIS", n1, n2);
    }
}