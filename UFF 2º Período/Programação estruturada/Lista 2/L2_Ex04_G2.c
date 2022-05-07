#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    char sorteio, letra;
    sorteio= 'a' + (char)(rand()%26);
    printf("Digite qual a letra foi sorteada: ");
    scanf("%c", &letra);
    if (((int)letra) == ((int)sorteio))
        printf("A letra foi a sorteada");
    else if (((int)letra) > ((int)sorteio))
        printf("A letra e maior que a sorteada");
    else
        printf("A letra e menor que a sorteada");
    return 0;
}
