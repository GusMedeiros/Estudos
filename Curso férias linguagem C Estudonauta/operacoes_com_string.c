#include <stdio.h>
#include <string.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    char nome[10] = "Gustavo";
    int tamanho = strlen(nome);
    printf("O nome %s tem %d letras.\n", nome, tamanho);
    printf("Insira um nome para comparar com %s: ", nome);
    char nome2[10];
    fflush(stdin);
    gets(nome2);
    fflush(stdin);

    int comparacao = strcmp(nome, nome2);
    printf("A comparação entre %s e %s resulta em %d\n", nome, nome2, comparacao);
    printf("Isso significa que, na linguagem c, %s %s %s.\n", nome, (strcmp(nome,nome2)==0)?"==":(strcmp(nome,nome2)>0)?">":"<", nome2);
    printf("Fun fact: o nome %s todo em minúsculo é ", nome2);
    printf("%s. ",strlwr(nome2));
    printf("Já em maiúsculo, é %s.", strupr(nome2));

}
