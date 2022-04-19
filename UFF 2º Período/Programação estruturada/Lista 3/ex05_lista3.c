#include <stdio.h>
#include <locale.h>
float max_vet(int n, float *vet);

void main()
{
    setlocale(LC_ALL, "Portuguese");
    int tamanho;
    printf("Vou pedir para você criar um vetor de floats e lhe direi o maior número dele.\n");
    printf("Qual vai ser o tamanho do seu vetor? ");
    scanf("%d", &tamanho);
    float vetor[tamanho];
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("Insira o número de índice %d do vetor: ", contador);
        fflush(stdin);
        scanf("%f", &vetor[contador]);
    }
    printf("O vetor é:\n");
    printf("[");
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("%.2f", vetor[contador]);
        if (contador < (tamanho - 1))
            printf(", ");
    }
    printf("].\n");
    printf("O seu maior elemento é: %.2f\n", max_vet(tamanho, vetor));
    // printf("Original: %x\n", &vetor); // testando se está duplicando ou passando por referencia
    // passar vetor e passar &vetor[0] é a mesma coisa, então não há erro aqui ^
}

float max_vet(int n, float *vet)
{
    float maior = vet[0];
    for (int i = 0; i < n; i++)
    {
        if (maior < vet[i])
        maior = vet[i];
    }
    // printf("Copia(?) :%x\n", vet); // testando se estava duplicando ou passando por referencia
    return maior;
}