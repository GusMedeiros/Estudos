#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Qual foi o valor total das compras? R$");
    float valortotal;
    fflush(stdin);
    scanf("%f", &valortotal);
    printf("------------------------------\n");
    printf("Voc� comprou R$%.2f na nossa loja.\n", valortotal);
    if (valortotal >= 500) {
        float valor_desconto = 0.1 * valortotal;
        valortotal *= 0.9;
        printf("========== ATEN��O ==========\n");
        printf("Por fazer mais de R$500 em compras, voc� vai receber R$%.2f de desconto\n", valor_desconto);
        printf("O valor a ser pago � R$%.2f! ", valortotal);
    }
    printf("Volte sempre!\n");
    printf("------------------------------\n");
}