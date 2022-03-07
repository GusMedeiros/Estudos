#include<stdio.h>
#include<locale.h>
#include<time.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    time_t t;
    time(&t);
    struct tm *data;
    data = localtime(&t);
    int ano_atual = data -> tm_year + 1900;

    printf("Atualmente estamos no ano de %d.\n", ano_atual);
    printf("Em que ano você nasceu? ");
    int ano_nasc;
    fflush(stdin);
    scanf("%d", &ano_nasc);
    int idade = ano_atual - ano_nasc;
    printf("--------------------------------------------------\n");
    printf("Sua idade atual é de %d anos.\n", idade);
    if (idade == 18) {
        printf("Você completa 18 anos exatamente em %d. Vá se alistar!\n", ano_atual);
    }
    else {
    int ano_alistamento = ano_nasc + 18;
    if (idade > 18) {
            printf("Seu alistamento foi em %d. Já se passaram %d anos.\n", ano_alistamento, ano_atual - ano_alistamento);
        }
        else {
            printf("Seu alistamento será em %d. Ainda faltam %d anos.\n", ano_alistamento, ano_alistamento - ano_atual);
        }
    }
    printf("--------------------------------------------------\n");

}