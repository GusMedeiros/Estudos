#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite uma letra: ");
    
    fflush(stdin);
    char letra = getchar();
    fflush(stdin);
    
    char antecessor = letra - 1;
    char sucessor = letra + 1;
    printf("Antes da letra %c temos a letra %c. Depois temos a letra %c.\n", letra, antecessor, sucessor);

}