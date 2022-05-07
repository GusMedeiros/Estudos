#include<stdio.h>

void inverte(unsigned int n);

int main(){

    unsigned int numero;

    printf("Digite o numero que gostaria de inverter: ");
    scanf("%u", &numero);

    inverte(numero);

    return 0;
}

void inverte(unsigned int n){
    int inv = 0;
    while (n > 0) {
        inv = 10 * inv + n % 10;
        n /= 10;
    }

    printf("Numero invertido: %d", inv);
}

