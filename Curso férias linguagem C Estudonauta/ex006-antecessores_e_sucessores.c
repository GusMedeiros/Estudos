#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um n�mero inteiro: ");
    int numero, antecessor, sucessor;
    fflush(stdin);
    scanf("%d", &numero);
    fflush(stdin);
    antecessor = numero - 1;
    sucessor = numero + 1;
    printf("Analisando o n�mero %d, seu antecessor � %d e seu sucessor � %d", numero, antecessor, sucessor);
    
}