#include <stdio.h>

int main()
{
    char operador;
    int a1 = 3, b1 = a1/2, c1 = b1+3.1;
    float a2 = 3, b2 = a2/2, c2 = b2+3.1;
    float a3 = 3, b3 = a1/2, c3 = b3+3.1;

    printf("Temos a=3\n b=a/2\n c = b+3.1\n");
    printf("Digite 'i' caso queira operacoes entre inteiros\n 'f' caso queira operacoes entre floats\n 'm' caso queira operacoes misturadas\n");
    scanf("%c", &operador);

    switch(operador)
    {
        case 'i':
        printf("O valor de c = %d pois temos uma divisao e soma entre inteiros (3/2 = 1 e 1+3.1 = 4)", c1);
        break;

        case 'f':
        printf("O valor de c = %g pois temos uma divisao e soma entre floats (3/2 = 1.5 e 1.5+3.1 = 4.6)", c2);
        break;

        case 'm':
        printf("O valor de c = %g pois temos uma divisao entre inteiros com uma soma float (3/2 = 1 e 1+3.1 = 4.1)", c3);
        break;
    }
    return 0;
}
