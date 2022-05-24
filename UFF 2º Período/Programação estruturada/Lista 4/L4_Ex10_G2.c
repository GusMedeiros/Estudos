#include <stdio.h>
#include <stdlib.h>

main()
{
    char nota;
    int idade, otimo=0, otimomaior=0, bom=0, regular=0, ruimmaior=0, pessimo=0, pessimomaior=0, i;
    float somaIdadeRuim=0, ruim=0;

    printf("Pesquisa do Cinema\n");

    printf("Legenda de Notas e seu significado\n");
    printf("\nA -  Otimo");
    printf("\nB -  Bom");
    printf("\nC -  Regular");
    printf("\nD -  Ruim");
    printf("\nE -  Pessimo\n\n");

    for(i=1; i<=20; i++)
    {
        printf("%d - Digite sua idade: ", i);
        scanf("%d", &idade);

        do{
            printf("Nota: ");
            scanf("%c", &nota);
        }
        while((nota != 'A')&&(nota != 'B')&&(nota != 'C')&&(nota != 'D')&&(nota != 'E'));

        if(nota == 'A'){
            otimo++;
            if(idade >= ruimmaior)
                otimomaior = idade;
        }
        else if(nota == 'B')
            bom++;
        else if(nota == 'C')
            regular++;
        else if(nota == 'D'){
            ruim++;
            somaIdadeRuim = somaIdadeRuim + idade;
            if(idade >= ruimmaior)
                ruimmaior = idade;
        }else{
            pessimo++;
            if(idade >= pessimomaior)
                pessimomaior = idade;
        }  
    }
    printf("\n\nQuantidade de respostas 'Otimo': %d", otimo);
    printf("\nDifererenca percentual das respostas 'Bom' e 'Regular': %d%%",(bom - regular));
    printf("\nMedia de idade das pessoas que responderam 'Ruim': %0.2f", (somaIdadeRuim / ruim));
    printf("\nPorrcentagem de respostas 'Pessimo': %d%%", pessimo);
    printf("\nMaior idade que utilizou a opcao 'Pessimo': %d", pessimomaior);
    printf("\nDiferenca de idade entre a maior idade que respondeu 'Otimo' e a maior idade que respondeu 'Ruim': %d", (otimomaior - ruimmaior));

    
}