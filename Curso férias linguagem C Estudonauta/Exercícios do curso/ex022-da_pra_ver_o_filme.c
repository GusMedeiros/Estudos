#include <stdio.h>
#include <locale.h>
#include <time.h>
void main() {
    
    setlocale(LC_ALL,"Portuguese");
    printf("========================== CINEMA ESTUDONAUTA ==========================\n");
    printf("HORÁRIO DO FILME: 19h - PREÇO DO INGRESSO: R$20\n");
    printf("------------------------------------------------------------------------\n");
    printf("Quanto dinheiro você tem? R$");
    float carteira;
    fflush(stdin);
    scanf("%f", &carteira);
    
    time_t t; // declarando variavel do tipo time_t
    time(&t); // usando a função time e passando pra ela o endereço da variável t
    struct tm *data; // criando uma estrutura tm e fazendo data apontar p ela
    data = localtime(&t);
    int hora = data -> tm_hour;
    printf("Agora são %d horas.\n", hora);
    if (hora > 19 || carteira < 20) {
        printf("Infelizmente não é possível comprar o ingresso!");
        }
    else {
        printf("Você consegue comprar o ingresso!");
    }
}