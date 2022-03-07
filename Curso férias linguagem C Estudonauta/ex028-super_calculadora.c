#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    float val1, val2;
    printf("Valor 1 = ");
    fflush(stdin);
    scanf("%f", &val1);
    printf("Valor 2 = ");
    fflush(stdin);
    scanf("%f", &val2);
    printf("=================\n");
    printf("+\tAdição\n");
    printf("-\tSubtração\n");
    printf("*\tMultiplicação\n");
    printf("/\tDivisão\n");
    printf("=================\n");
    printf("Digite sua opção => ");
    fflush(stdin);
    char operacao = getchar();
    printf("---------------------------------------------------\n");
    printf("O resultado de 5 %c 8 é igual a ", operacao);
    switch (operacao) {
        case '+':
            printf("%.1f.\n", val1 + val2);
            break;
        case '-':
            printf("%.1f.\n", val1 - val2);
            break;
        case '*':
            printf("%.1f.\n", val1 * val2);
            break;
        case '/':
            printf("%.1f.\n", val1 / val2);
            break;
        default:
            printf("... ERRO! OPERAÇÃO NÃO RECONHECIDA\n");
    }
    printf("---------------------------------------------------\n");
    printf("VOLTE SEMPRE\n");
}