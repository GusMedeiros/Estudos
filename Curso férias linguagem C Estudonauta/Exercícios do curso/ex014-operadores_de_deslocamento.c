#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um número: ");
    fflush(stdin);
    int numero, deslocamento;
    scanf("%d", &numero);
    printf("Digite o deslocamento: ");
    fflush(stdin);
    scanf("%d", &deslocamento);
    printf("------- OPERAÇÕES SHIFT -------\n");
    printf("Calculando %d >> %d é igual a %d\n", numero, deslocamento, numero>>deslocamento);
    printf("Calculando %d << %d é igual a %d\n", numero, deslocamento, numero<<deslocamento);
}