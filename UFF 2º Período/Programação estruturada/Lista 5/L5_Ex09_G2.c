#include <string.h>
#include <stdio.h>

void main() {
    char nome[100], endereco[100], telefone[12];
    printf("Insira o nome: ");
    gets(nome);
    printf("Insira o endereco: ");
    gets(endereco);
    printf("Insira o telefone: ");
    gets(telefone);
    int len = strlen(nome) + strlen(endereco) + strlen(telefone);
    char cat[len];
    strcpy(cat, nome);
    strcat(cat, endereco);
    strcat(cat, telefone);
    printf("%s", cat);
}