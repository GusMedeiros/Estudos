#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o preço de um produto em R$: ");
    float preco;
    fflush(stdin);
    scanf("%f", &preco);
    printf("\t ESCOLHA UM PERÍODO\n");
    printf("\t====================\n");
    printf("\t1\tCarnaval [+10%%]\n");
    printf("\t2\tFérias Escolares [+20%%]\n");
    printf("\t3\tDia das Crianças [+5%%]\n");
    printf("\t4\tBlack Friday [-30%%]\n");
    printf("\t5\tNatal [-5%%]\n");
    printf("\t====================\n");
    printf("Digite sua opção => ");
    fflush(stdin);
    int opcao;
    scanf("%d", &opcao);
    printf("------------------------------------------------------------\n");
    switch (opcao) {
        case 1:
            printf("Na época do CARNAVAL, o preço do produto vai para R$%.2f.\n", preco * 1.1);
            break;
        case 2:
            printf("Na época das FÉRIAS, o preço do produto vai para R$%.2f.\n", preco * 1.2);
            break;
        case 3:
            printf("Na época do DIA DAS CRIANÇAS, o preço do produto vai para R$%.2f.\n", preco * 1.05);
            break;
        case 4:
            printf("Na época da BLACK FRIDAY, o preço do produto vai para R$%.2f.\n", preco * 0.7);
            break;
        case 5:
            printf("Na época do NATAL, o preço do produto vai para R$%.2f.\n", preco * 0.95);
            break;
        default:
            printf("Em épocas assim, mantenha o preço do produto em R$%.2f.\n", preco);
            break;

    }
    printf("------------------------------------------------------------\n");
}