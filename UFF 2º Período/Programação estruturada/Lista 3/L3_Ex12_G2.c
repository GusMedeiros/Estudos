#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 81
char* palavra(char frase[], char *palav, int inicio, int tamanho);
char frase[max], *palavra_atual, char_atual = 'a';
int indice = 0, inicio_palavra = 0, fim_palavra = 0, tamanho_palavra = 0;
int main()
{
while(char_atual != '\r' && indice < max)
    {   
        char_atual = getch();
        fflush(stdin);
        frase[indice] = char_atual;
        // printf("%c", frase[indice]);
        if (char_atual == '\r' || char_atual == ' ' || char_atual == '.'|| char_atual == ',' || char_atual == ';'|| char_atual == ":")
        {
            if (char_atual == '\r')
            {
                frase[indice] = '\0';
            }
            //printf("entrei no if\n");
            fim_palavra = indice;
            tamanho_palavra = (fim_palavra - inicio_palavra);
            //printf("%d\n", tamanho_palavra);
            palavra_atual = malloc(sizeof(char) * (tamanho_palavra));
            //printf("\n%x\n", palavra_atual); // endereco
            palavra_atual = palavra(frase, palavra_atual, inicio_palavra, tamanho_palavra);
            inicio_palavra = indice + 1;
            for (int c = 0; c < tamanho_palavra; c++)
            {
            printf("%c", palavra_atual[c]);
            }
            printf("\n");
        }
        indice++;

    }
    //printf("fim\n");
    return 0;
}
char* palavra(char frase[], char *palav, int inicio, int tamanho)
{
    //printf("Entrei na funcao\n");
    //printf("palavra = %s", palavra_atual);
    for (int i = 0;i < tamanho; i++)
    {
        palav[i] = frase[inicio + i];
        // printf("%c, %d\n", palav[i], tamanho);
    }
    // printf("%s", palav);
    return palav;
}