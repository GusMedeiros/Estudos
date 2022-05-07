#include <stdio.h>
#include <math.h>


void calc_circulo(float r, float *circunferencia, float *area){
    *circunferencia=2*M_PI*r;
    *area=M_PI*r*r;
    printf("Circunferencia: %f\n", *circunferencia);
    printf("Area: %f", *area);
}

int main (void){
    float r, circunferencia, area;
    printf("Digite o raio do circulo: ");
    scanf("%f", &r);
    calc_circulo(r, &circunferencia, &area);
    return 0;
}
