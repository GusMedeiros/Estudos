#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

int main(void){
    int i=0, n=0;
    float soma, media, variancia;
    int fim = 0, str_len;
    char nome[MAX_SIZE], **nomes;

    while( !fim ){
        printf("Digite o %do nome: ", i+1);
        scanf(" %[^\n]", nome);

        if( strcmp(nome, "fim")!=0 ){
            if(i==0){
                nomes = (char **) malloc( sizeof(char *));
            }
            else{
                nomes = (char **) realloc(nomes, (i+1)*sizeof(char *));
            }
            if(nomes==NULL){ 
                printf("MEMORIA INSUFICIENTE");
                free(nomes);
                exit(1);
            }

            nomes[i] = (char *) malloc( (strlen(nome)+1)*sizeof(char) );
            if(nomes[i]==NULL){ 
                printf("MEMORIA INSUFICIENTE");
                free(nomes);
                exit(1);
            }
            
            strcpy( nomes[i], nome );
            i++;
        }
        else{
            fim = 1;
        }   
    }
    n = i;

    // Calculo da Media
    soma = 0;
    for(i=0; i<n; i++){
        soma += strlen(nomes[i]);
    }
    media = soma/n;

    // Calculo da Variancia
    soma = 0;
    for(i=0; i<n; i++){
        str_len = strlen(nomes[i]);
        soma += (str_len-media)*(str_len-media);
    }
    variancia = soma/n;

    printf("\nMedia do tamanho dos nomes = %.2f", media);
    printf("\nVariancia do tamanho dos nomes = %.2f", variancia);

    free(nomes);

    return 0;
}