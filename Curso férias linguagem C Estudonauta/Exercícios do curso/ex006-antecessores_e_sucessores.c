#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um número inteiro: ");
    int numero, antecessor, sucessor;
    fflush(stdin);
    scanf("%d", &numero);
    fflush(stdin);
    antecessor = numero - 1;
    sucessor = numero + 1;
    printf("Analisando o número %d, seu antecessor é %d e seu sucessor é %d", numero, antecessor, sucessor);
    
}