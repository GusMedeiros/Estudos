#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Digite a sua primeira nota: ");
    fflush(stdin);
    float nota1, nota2;
    scanf("%f", &nota1);
    printf("Digite a sua segunda nota: ");
    fflush(stdin);
    scanf("%f", &nota2);
    float media = (nota1+nota2)/2;
    printf("----------------------------\n");
    if (media >=7) {
        printf("Meus parabéns! ");
    }
    printf("A sua média final foi %.1f\n", media);
    printf("----------------------------\n");
}
