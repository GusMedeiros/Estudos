#include<stdio.h>
#include<time.h>
#include<locale.h>
void main() {
    setlocale(LC_ALL, "Portuguese");
    time_t tempo;
    time(&tempo);
    struct tm *data;
    data = localtime(&tempo);
    int ano = data -> tm_year + 1900;
    printf("Atualmente estamos no ano de %d.\n", ano);
    printf("Em que ano voc� nasceu? ");
    int nascimento;  
    fflush(stdin);
    scanf("%d", &nascimento);
    int idade = ano - nascimento;
    printf("-----------------------------------\n");
    printf("Sua idade atual � de %d anos.\n", idade );
    if (idade >= 18) {
        printf("J� fez 18 anos. Espero sinceramente que voc� tenha se alistado.");
    }
    else {
        printf("Voc� ainda n�o tem 18 anos. N�o pode se alistar.");
    }

}