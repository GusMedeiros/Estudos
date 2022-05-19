#include <stdio.h>

void printavetor(int tamanho, int *vetor)
{
    for (int i=0; i<tamanho; i++)
    {
        printf("%d,", vetor[i]);
    }
    printf("\n");
}

int bubblesort(int tamanho, int *vetor)
{   
    int j = 0;
    while (j < tamanho - 1)
    {
    j = 0;
    printavetor(tamanho, vetor);
    for (int i = 0; i < tamanho - 1; i++)// itera uma vez trocando elementos
    {
        if (vetor[i] > vetor[i+1]){
            int a = vetor[i];
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
    int vetor[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubblesort(10, vetor);
}