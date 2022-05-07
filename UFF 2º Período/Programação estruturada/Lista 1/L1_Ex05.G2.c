#include <stdio.h>

int main()
{
    int a1 = 3, b1 = a1/2, c1 = b1+3.1;
    float a2 = 3, b2 = a2/2, c2 = b2+3.1;
    float a3 = 3, b3 = a1/2, c3 = b3+3.1;

    printf("Temos a=3\n b=a/2\n c=b+3.1 \n");
    printf("Caso a operacao seja entre inteiros, obteremos: %d, \nCaso a operacao seja entre pontos flutuantes, obteremos: %.2f, \nCaso seja uma divisao de inteiro com uma soma de ponto flutuantes, obteremos: %.2f, \n", c1, c2, c3);
    printf("\nIsto acontece, pois quando dividimos inteiros a parte decimal eh ignoroda e quando criamos uma variavel inteira que soma um inteiro com um float, ela retorna um inteiro sem casa decimal.");
    return 0;
}
