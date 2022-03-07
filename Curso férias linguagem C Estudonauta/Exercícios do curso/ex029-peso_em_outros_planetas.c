#include<stdio.h>
#include <locale.h>
void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Seu peso na terra(Kg) :");
    float peso;
    fflush(stdin);
    scanf("%f", &peso);
    
    printf("\n\t ESCOLHA UM PLANETA\n");
    printf("\t=====================\n");
    printf("\t1\tMercúrio\n");
    printf("\t2\tVênus\n");
    printf("\t3\tMarte\n");
    printf("\t4\tJúpiter\n");
    printf("\t5\tSaturno\n");
    printf("\t6\tUrano\n");
    printf("\t7\tNetuno\n");
    printf("\t======================\n");
    printf("Digite sua opção => ");
    int opcao;
    fflush(stdin);
    scanf("%d", &opcao);


    printf("\n---------------------------------------------------------\n");
    switch (opcao) {
        case 1: // mercurio
            printf("No planeta Mercúrio, seu peso seria %.2f Kg\n", peso * 0.37);
            break;

        case 2: // venus
            printf("No planeta Vênus, seu peso seria %.2f Kg\n", peso * 0.88);
            break;

        case 3: // marte
            printf("No planeta Marte, seu peso seria %.2f Kg\n", peso * 0.38);
            break;

        case 4: // jupiter
            printf("No planeta Júpiter, seu peso seria %.2f Kg\n", peso * 2.64);
            break;
        
        case 5: // saturno
            printf("No planeta Saturno, seu peso seria %.2f Kg\n", peso * 1.15);
            break;

        case 6: // urano
            printf("No planeta Urano, seu peso seria %.2f Kg\n", peso * 1.17);
            break;

        case 7: // netuno
            printf("No planeta Netuno, seu peso seria %.2f Kg\n", peso * 1.18);
            break;

        default:
            printf("ERRO: PLANETA NÃO EXISTE\n");
            break;
    }
    printf("---------------------------------------------------------\n");
    printf("VOLTE SEMPRE");
}