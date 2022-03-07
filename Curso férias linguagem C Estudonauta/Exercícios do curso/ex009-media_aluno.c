#include <stdio.h>
#include <locale.h>
void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Nome do aluno: ");
    char nome[20]; 
    fflush(stdin);
    gets(nome);
    fflush(stdin);
    float nota1; 
    printf("Nota 1: ");
    scanf("%f", &nota1);
    fflush(stdin);
    float nota2; 
    printf("Nota 2: ");
    scanf("%f", &nota2);
    fflush(stdin);
    float media = (nota1 + nota2) / 2;
    printf("O aluno %s tirou notas %.1f e %.1f e ficou com média %.1f\n", nome, nota1, nota2, media);
    printf("O aluno está %s", media>=6?"aprovado":"reprovado");
}