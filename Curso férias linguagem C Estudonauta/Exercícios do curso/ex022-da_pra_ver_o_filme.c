#include <stdio.h>
#include <locale.h>
#include <time.h>
void main() {
    
    setlocale(LC_ALL,"Portuguese");
    printf("========================== CINEMA ESTUDONAUTA ==========================\n");
    printf("HOR�RIO DO FILME: 19h - PRE�O DO INGRESSO: R$20\n");
    printf("------------------------------------------------------------------------\n");
    printf("Quanto dinheiro voc� tem? R$");
    float carteira;
    fflush(stdin);
    scanf("%f", &carteira);
    
    time_t t; // declarando variavel do tipo time_t
    time(&t); // usando a fun��o time e passando pra ela o endere�o da vari�vel t
    struct tm *data; // criando uma estrutura tm e fazendo data apontar p ela
    data = localtime(&t);
    int hora = data -> tm_hour;
    printf("Agora s�o %d horas.\n", hora);
    if (hora > 19 || carteira < 20) {
        printf("Infelizmente n�o � poss�vel comprar o ingresso!");
        }
    else {
        printf("Voc� consegue comprar o ingresso!");
    }
}