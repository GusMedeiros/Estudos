#include <stdio.h>
#include <stdlib.h>
void main() {
    printf("Insira o nome do arquivo: ");
    char nome_arquivo[40]; 
    gets(nome_arquivo);
    FILE *f = fopen(nome_arquivo, "r");
    if (f == NULL) {
        printf("Falha ao abrir o arquivo");
        exit(-1);
    }
    int qtdnumeros = 0;
    float numero, soma = 0;
    while(fscanf(f ,"%f", &numero) == 1) {
        qtdnumeros++;
        soma += numero;
    }
    printf("A media dos numeros contidos no arquivo %s e de %.2f.", nome_arquivo, soma/qtdnumeros);
}