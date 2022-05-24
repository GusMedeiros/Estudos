/*
12. Fazer um programa para receber uma string do usuário (máx. 50 caracteres) e fazer uma
estatística dos caracteres digitados. Por exemplo, para a string "O EXERCICIO E FACIL"”, a
estatística mostrada será 'O' = 2, ' '=3, 'E' = 3, 'X' = 1, 'R' = 1, 'C' = 3, 'I' = 3, 'F' = 1, 'A' = 1, 'L' = 1
*/
#include <stdio.h>
#include <string.h>

void printavetor(int tamanho, char *vetor)
{
    for (int i=0; i<tamanho; i++)
    {
        printf("%c,", vetor[i]);
    }
    printf("\n");
}

char* bubblesort(int tamanho, char *vetor)
{   
    int j = 0;
    while (j < tamanho - 1)
    {
    j = 0;
    // printavetor(tamanho, vetor);
    for (int i = 0; i < tamanho - 1; i++) // itera uma vez trocando elementos
    {
        //if (vetor[i] == ' ' && vetor[i])
        if (vetor[i] > vetor[i+1] && vetor[i+1] != '\0')
        {
            char a = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = a;
        }
        else j++;
    }
    }
    return vetor;
}


void main()
{
    char string[50], copia_sorted[50], unicos[50];
    int numeros[50];
    gets(string);
    strcpy(copia_sorted, string);
    copia_sorted[strlen(string)] = '\0';
    bubblesort(strlen(copia_sorted), copia_sorted);
    char caractere_atual = '\0';
    int u = -1;
    for(int i=0; copia_sorted[i] != '\0'; i++)
    {
        if (copia_sorted[i] != caractere_atual) // se for um novo caractere
        {
            caractere_atual = copia_sorted[i];
            u++;
            numeros[u] = 1;  // preenchemos um novo espaço nos únicos e números
            unicos[u] = caractere_atual;
        }
        else 
        {
            numeros[u]++;
        }
    }
    // até essa linha, u corresponde ao índice do último elemento de unicos[] e numeros[].
    u++;
    for(int i = 0; i < u; i++){
        printf("'%c'= %d", unicos[i], numeros[i]);
    }
    }