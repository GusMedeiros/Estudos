/* 
4. Fazer uma função denominada divs() que:
a. recebe como parâmetro um número inteiro n por valor e dois números inteiros max e min por
referência;
b. retorna 0 se o número num é primo e 1 caso contrário. Se o número não for primo, as variáveis
max e min devem assumir os valores do menor e do maior divisores inteiros do número,
respectivamente, desconsiderando o número 1 e o próprio número num. 
*/
#include <stdio.h>
int divs(int n, int *max, int *min){
    if (n > 1){
        int primeirodivisor = 0;
        int primo = 1;
        for (int numerodecomparacao = n - 1; numerodecomparacao > 1; numerodecomparacao--){
            if (n % numerodecomparacao == 0) // é divisor
            {
                primo = 0;
                if (numerodecomparacao < *min) {
                    *min = numerodecomparacao;
                }
                if (primeirodivisor == 0){
                    primeirodivisor = 1;
                }
                if(primeirodivisor == 1) 
                {
                    *max = numerodecomparacao;
                    primeirodivisor = 2;
                }
            }
        }
        if (primo){
            return 0;
        }
        else {
            return 1;
        }
    }
}

void main() {
    int maiordivisor = 0, menordivisor = 0, numero = 7;
    
    printf("ehprimo = %d, max = %d, min = %d ", divs(numero, &menordivisor, &maiordivisor));
}