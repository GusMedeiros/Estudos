#include <stdio.h>
#include <locale.h>

char nome[15];
int idade;
float peso;

void main() {
    
    setlocale(LC_ALL, "Portuguese");
    printf("Qual � o seu nome? ");
    gets(nome);
    fflush(stdin);
    printf("Quantos anos voc� tem? ");
    scanf("%d", &idade);
    fflush(stdin);
    printf("Qual � o seu peso? (Kg) ");
    scanf("%f", &peso);
    fflush(stdin);
    printf("--------<<< PROCESSANDO >>>---------\n");
    printf("Muito prazer, %s. Voc� tem %d anos e pesa %.2fKg, correto?\n", nome, idade, peso);
    printf("FIM.");
}