/* 10. Implemente um programa que chame a fun��o m�dia com o seguinte prot�tipo:
float media(int n, float *v)*/

#include <stdio.h>
#include <locale.h>
float media(int n, float *v);

void main()
{
    setlocale(LC_ALL,"Portuguese");
    printf("Bem-vindo � calculadora de m�dia! Insira de quantos valores quer a m�dia: ");
    int tamanho; 
    scanf("%d", &tamanho);
    printf("Ok, vou ent�o te pedir %d valores reais:\n", tamanho);
    float valores[tamanho];
    
    for (int i = 0; i < tamanho; i++)
    {
        printf("Insira o valor %d:" , i + 1);
        fflush(stdin);
        scanf("%f", &valores[i]);
    }

    printf("Calculei! A m�dia desses valores �: %.2f", media(tamanho, valores));
}

float media(int n, float *v)
{
    // assumindo que n � o tamanho do vetor de floats v:
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }
    return soma/n;
}