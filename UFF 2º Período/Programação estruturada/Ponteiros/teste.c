#include <stdio.h>
#include <stdlib.h>
void main()
{
    char *palavra_atual = malloc(sizeof(char) * (2));
    palavra_atual[0] = 'a';
    palavra_atual[1] = 'b';
    printf("%s", palavra_atual);

}