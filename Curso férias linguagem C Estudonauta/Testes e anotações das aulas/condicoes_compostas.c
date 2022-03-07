#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    float velocidade;
    printf("Qual é a velocidade do carro em Km/h? ");
    fflush(stdin);
    scanf("%f", &velocidade);
    printf("O limite de velocidade dessa rodovia é de 80 Km/h, com uma tolerância de 10%%.\n");
    printf("Veículos acima desse limite receberão uma multa de R$ 150 + R$4,50 para cada Km/h excedente.\n");
    if (velocidade > 88) {
        printf("Infelizmente você está acima da tolerância de 10%%, o que lhe rendeu uma multa de R$%.2f", 150 + 4.5*(velocidade-88));
    }
    else {
        printf("Você está respeitando os limites de velocidade! Boa viagem, dirija com segurança!");
    }
}