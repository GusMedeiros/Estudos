#include <stdio.h>
#include <locale.h>
#include <time.h>
void main() {
    setlocale(LC_ALL, "Portuguese");
    time_t t; // aloca um endere�o chamado computer_time
    time(&t); // salva no endere�o computer_time o tempo
    struct tm *data; // 
    data = localtime(&t);
    int ano = data -> tm_year + 1900;
    printf("Em que ano voc� nasceu? ");
    int ano_nasc;
    scanf("%d", &ano_nasc);
    printf("---------------------------\n");
    int idade = ano - ano_nasc;
    printf("VoC� tem %d anos, certo?\n", idade);
    printf("Seja bem-vindo(a) ao banco Estudonauta!\n");
    if (idade >= 65) {
        printf("=== ATEN��O! DIRIJA-SE PARA A FILA PREFERENCIAL ===\n");
        }
    printf("---------------------------\n");
}