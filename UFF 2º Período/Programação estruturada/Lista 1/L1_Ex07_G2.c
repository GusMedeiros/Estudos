#include <stdio.h>
#include <math.h>

int main()
{
    float x,x_decimal;
    printf("O valor float de x  = ");
    scanf("%f", &x);

    x_decimal = x - (int)x;

    if (x_decimal >= 0.5)
    {
        printf("Arredondando temos: x = %.g\n", ceil(x));
    }
    else
    {
        printf("Arredondando temos: x = %.g\n", floor(x));
    }

    return 0;
}
