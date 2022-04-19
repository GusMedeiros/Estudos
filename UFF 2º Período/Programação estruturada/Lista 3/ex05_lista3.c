#include <stdio.h>
#include <locale.h>
float max_vet(int n, float *vet);

void main()
{
    setlocale(LC_ALL, "Portuguese");
    int tamanho;
    printf("Vou pedir para voc� criar um vetor de floats e lhe direi o maior n�mero dele.\n");
    printf("Qual vai ser o tamanho do seu vetor? ");
    scanf("%d", &tamanho);
    float vetor[tamanho];
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("Insira o n�mero de �ndice %d do vetor: ", contador);
        fflush(stdin);
        scanf("%f", &vetor[contador]);
    }
    printf("O vetor �:\n");
    printf("[");
    for (int contador = 0; contador < tamanho; contador++)
    {
        printf("%.2f", vetor[contador]);
        if (contador < (tamanho - 1))
            printf(", ");
    }
    printf("].\n");
    printf("O seu maior elemento �: %.2f\n", max_vet(tamanho, vetor));
    // printf("Original: %x\n", &vetor); // testando se est� duplicando ou passando por referencia
    // passar vetor e passar &vetor[0] � a mesma coisa, ent�o n�o h� erro aqui ^
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