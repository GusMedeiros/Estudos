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
    printf("Em que ano voc� nasceu? ");
    int ano_nasc;
    fflush(stdin);
    scanf("%d", &ano_nasc);
    int idade = ano_atual - ano_nasc;
    printf("--------------------------------------------------\n");
    printf("Sua idade atual � de %d anos.\n", idade);
    if (idade == 18) {
        printf("Voc� completa 18 anos exatamente em %d. V� se alistar!\n", ano_atual);
    }
    else {
    int ano_alistamento = ano_nasc + 18;
    if (idade > 18) {
            printf("Seu alistamento foi em %d. J� se passaram %d anos.\n", ano_alistamento, ano_atual - ano_alistamento);
        }
        else {
            printf("Seu alistamento ser� em %d. Ainda faltam %d anos.\n", ano_alistamento, ano_alistamento - ano_atual);
        }
    }
    printf("--------------------------------------------------\n");

}