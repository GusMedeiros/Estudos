#include<stdio.h>
#include<math.h>


int main(){

    int numero1, numero2, resultado;

    scanf("%d", &numero1);
    scanf("%d", &numero2);

    resultado = pow(numero1, numero2);

    printf("%d", resultado);

    return 0;
}
