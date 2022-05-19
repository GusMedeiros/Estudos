#include <stdio.h>
#include <stdlib.h>

int gDistancia;

void calcula_corrida(float dist, float *b1, float *b2){

    dist = 4.95;
    *b1 = 2.50;
    *b2 = 3.00;
    *b1 = dist + *b1 * gDistancia;
    *b2 = dist + *b2 * gDistancia;

}

int main (void){

    float d, band1, band2;

    printf("Digite a distancia em km: ");
    scanf("%i", &gDistancia);
    calcula_corrida(d, &band1, &band2);
    printf("O valor a bandeira 1 eh %0.2f e para bandeira 2 eh %0.2f", band1, band2);


    return 0;
}
