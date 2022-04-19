#include <stdio.h>
#include <locale.h>
#include <math.h>
int mulheresadultas(int age[], char sex[], int qtd) // mesmo que int *age e char *sex
{
    // printf("copia(?) = %x ", &age[0]); // testando se passou por valor ou referencia
    int contador = 0;
    for (int i = 0; i < qtd; i++)
    {
        if (sex[i] == 'F' && 20 <= age[i] && age[i] <= 35)
            contador++;
    }
    return contador;
}
int homensmaiores180(float *h, char sex[], int qtd)
{
    int contador = 0;
    for (int i = 0; i < qtd; i++)
    {
        if (h[i] > 1.8 && sex[i] == 'M')
            contador++;
    }
    return contador;
}
float variancialtura(float *h, int qtd)
{
    float soma = 0;
    for (int i = 0; i < qtd; i++)
    {
        soma += h[i];
    }
    float media = soma / qtd;
    soma = 0;
    for (int i = 0; i < qtd; i++)
    {
        soma += pow(h[i] - media, 2);
    }
    return soma / (qtd - 1);
}
void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Quantas pessoas vamos testar? ");
    int n;
    scanf("%d", &n);
    
    int idades[n]; float alturas[n]; char sexos[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nInsira as informações da pessoa %d:\n", i+1);
        printf("Idade: ");
        fflush(stdin);
        scanf("%d", &idades[i]);
        
        printf("Altura em M: ");
        fflush(stdin);
        scanf("%f", &alturas[i]);

        printf("Sexo (M/F): ");
        fflush(stdin);
        sexos[i] = getchar();
    }

    // printf("original = %x", idades); // testando se passou por valor ou referencia
    printf("Você inseriu %d mulheres com idade entre 25 e 35 anos.\n", mulheresadultas(idades, sexos, n));
    printf("Você inseriu %d homens com altura maior que 180cm.\n", homensmaiores180(alturas, sexos, n));
    printf("A variância amostral de altura foi de %.2fm².\n", variancialtura(alturas, n));
}
