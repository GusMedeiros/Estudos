#include<stdio.h>
#include<locale.h>

// declare
char nome[20];
int idade;
float peso;
float altura;
char profissao[20];
float salario;

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Bem-vindo, vamos montar o seu perfil:\n");
    printf("Insira o seu nome: ");
    fflush(stdin);
    gets(nome);
    printf("Insira a sua idade em anos:");
    fflush(stdin);
    scanf("%d", &idade);
    printf("Insira o seu peso em Kg:");
    fflush(stdin);
    scanf("%f", &peso);
    printf("Insira sua altura em metros: ");
    fflush(stdin);
    scanf("%f", &altura);
    printf("Qual a sua profiss�o? - ");
    fflush(stdin);
    gets(profissao);
    printf("Quanto voc� ganha nela em reais? - ");
    fflush(stdin);
    scanf("%f", &salario);
    printf("Ent�o ficou assim:\n");
    printf("Nome: %s,\tIdade: %d anos\n", nome, idade);
    printf("Altura: %.2fm,\tPeso: %.3fKg\n", altura, peso);
    printf("Profiss�o: %s,\tSal�rio: R$%.2f", profissao, salario);
}
