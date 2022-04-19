#include <stdio.h>
#include <locale.h>
int maiores(int n, int * vet, int x);
void main()
{
    setlocale(LC_ALL,"Portuguese");
    printf("Diga um número e lhe direi quantas vezes encontrei um maior que ele no vetor [1, 10, 100].\n");
    int numero;
    scanf("%d", &numero);
    int vetor[] = {1, 10, 100};
    printf("Encontrei %d números maiores que %d.", maiores(3, vetor, numero), numero);
}
int maiores(int n, int * vet, int x)
{
    int maiores = 0;
    for (int contador = 0; contador < n; contador++)
    {
        if (x < vet[contador])
            maiores++;
    }
    return maiores;
}