#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Digite o pre�o de um produto em R$: ");
    float preco;
    fflush(stdin);
    scanf("%f", &preco);
    printf("\t ESCOLHA UM PER�ODO\n");
    printf("\t====================\n");
    printf("\t1\tCarnaval [+10%%]\n");
    printf("\t2\tF�rias Escolares [+20%%]\n");
    printf("\t3\tDia das Crian�as [+5%%]\n");
    printf("\t4\tBlack Friday [-30%%]\n");
    printf("\t5\tNatal [-5%%]\n");
    printf("\t====================\n");
    printf("Digite sua op��o => ");
    fflush(stdin);
    int opcao;
    scanf("%d", &opcao);
    printf("------------------------------------------------------------\n");
    switch (opcao) {
        case 1:
            printf("Na �poca do CARNAVAL, o pre�o do produto vai para R$%.2f.\n", preco * 1.1);
            break;
        case 2:
            printf("Na �poca das F�RIAS, o pre�o do produto vai para R$%.2f.\n", preco * 1.2);
            break;
        case 3:
            printf("Na �poca do DIA DAS CRIAN�AS, o pre�o do produto vai para R$%.2f.\n", preco * 1.05);
            break;
        case 4:
            printf("Na �poca da BLACK FRIDAY, o pre�o do produto vai para R$%.2f.\n", preco * 0.7);
            break;
        case 5:
            printf("Na �poca do NATAL, o pre�o do produto vai para R$%.2f.\n", preco * 0.95);
            break;
        default:
            printf("Em �pocas assim, mantenha o pre�o do produto em R$%.2f.\n", preco);
            break;

    }
    printf("------------------------------------------------------------\n");
}