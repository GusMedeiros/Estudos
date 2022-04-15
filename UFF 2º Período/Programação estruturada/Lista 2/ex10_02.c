#include<stdio.h>
#include<stdlib.h>
int MDC(int n1, int n2)
{
    int divisor;
    if (n1 <= n2)
        divisor = n1;
    else
        divisor = n2;
    while (1)
    {
        if ((n1 % divisor == 0) && (n2 % divisor == 0))
            return divisor;
        divisor--;
    }
}

void main()
{
    int n1, n2;
    printf("Insira o numero 1: ");
    scanf("%d", &n1);
    fflush(stdin);
    printf("Insira o numero 2: ");
    scanf("%d", &n2);
    printf("%d", MDC(n1, n2));
}