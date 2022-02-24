#include <stdio.h>
#include <locale.h>

char nome[15];
int idade;
float peso;

void main() {
    
    setlocale(LC_ALL, "Portuguese");
    printf("Qual é o seu nome? ");
    gets(nome);
    fflush(stdin);
    printf("Quantos anos você tem? ");
    scanf("%d", &idade);
    fflush(stdin);
    printf("Qual é o seu peso? (Kg) ");
    scanf("%f", &peso);
    fflush(stdin);
    printf("--------<<< PROCESSANDO >>>---------\n");
    printf("Muito prazer, %s. Você tem %d anos e pesa %.2fKg, correto?\n", nome, idade, peso);
    printf("FIM.");
}