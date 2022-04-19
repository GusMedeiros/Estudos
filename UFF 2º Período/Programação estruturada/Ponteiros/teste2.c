#include <stdio.h>
#define pontovirgula ;

int funcao(int *vetor)
{
    return vetor[2];
}

void main()
{
    int vetor[] = {1, 2, 3};
    printf("%s\n",funcao(vetor) == funcao(&vetor[0])?"True":"False");
    printf("%d", funcao(&vetor[0]));
}
