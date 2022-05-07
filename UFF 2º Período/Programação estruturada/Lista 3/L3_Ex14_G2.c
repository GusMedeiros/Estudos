#define MAX 5
#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
    int idade[MAX];
    int otimo = 0, bom = 0, regular = 0, ruim = 0, pessimo = 0, age = 0, soma = 0, maiorpessimo = 0;
    int maiorotimo = 0, maiorruim = 0;
    char opiniao[MAX];
    int i = 0;
    setlocale(LC_ALL,"Portuguese");
    while(i < MAX)
    {
        //printf("entrei no while\n");
        printf("Insira a idade do espectador #%d: ", i+1);
        scanf("%d", &age);
        idade[i] = age;
        fflush(stdin);
        printf("------------------------------------\n");
        printf("5 - ótimo\n");
        printf("4 - bom\n");
        printf("3 regular\n");
        printf("2 - ruim\n");
        printf("1 - péssimo\n");
        printf("Insira a opinião do espectador #%d:\n", i+1);
        int opcao;
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
            case 5:
                otimo += 1;
                break;
            
            case 4:
                bom += 1;
                if (age >= maiorotimo)
                {
                    maiorotimo = age;
                }
                break;
            
            case 3:
                regular += 1;
                break;
            
            case 2:
                ruim += 1;
                soma += age;
                if (age >= maiorruim)
                {
                    maiorruim = age;
                }
                break;

            case 1:
                pessimo += 1;
                if (age >= maiorpessimo)
                {
                    maiorpessimo = age;
                }
                break;
        }
        opiniao[i] = opcao;
        i++;
    }
    printf("----------------\n");
    printf("%d pessoas acharam o filme ótimo\n", otimo);
    printf("A diferenca de porcentagem entre bom e regular é de %.2f%%.\n", abs((float)bom/100.0 - (float)regular/100.0));
    printf("A média de idade das pessoas que responderam ruim é de %d anos.\n", (ruim==0)?0:soma/ruim);
    printf("A porcentagem de péssimos foi de %.2f%%. A maior idade que votou péssimo foi %d anos.\n", (float)pessimo/100.0, maiorpessimo);
    printf("A diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim é de: %d anos.", abs(maiorotimo - maiorruim));   
}
