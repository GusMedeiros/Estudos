#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main() {
    FILE *arquivo = fopen("arquivo_escrita", "wt");
    if (arquivo == NULL){
        printf("Erro na abertura de arquivo\n");
        exit(1);
    }
    printf("O que deseja escrever no arquivo? \n");
    char string[301];
    fflush(stdin);
    gets(string);
    fprintf(arquivo, string);
    

}