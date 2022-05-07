#include<stdio.h>
#include<stdlib.h>
int MDC(int n1, int n2)
{
    int i, maiorDiv, div;
    if (n1 <= n2)
        maiorDiv = n1;
    else
        maiorDiv = n2;

    div = maiorDiv;
    for (i=0;i<div;i++)
    {
        if ((n1%maiorDiv || n2%maiorDiv) != 0)
        {
            maiorDiv--;
        }
    }
    return maiorDiv;
}

void main()
{
    int num1, num2;
    printf("Insira o numero 1: ");
    scanf("%d", &num1);
    fflush(stdin);
    printf("Insira o numero 2: ");
    scanf("%d", &num2);
    printf("%d", MDC(num1, num2));
}
