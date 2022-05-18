#include <stdio.h>
#include <stdlib.h>
void main()
{
    char *palavra_atual = malloc(sizeof(char) * (3));
    palavra_atual[0] = 'a';
    palavra_atual[1] = 'b';
    palavra_atual[2] = '\0';
    printf("%s", palavra_atual);
}