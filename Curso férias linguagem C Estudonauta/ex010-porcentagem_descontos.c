#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Produto: ");
    char produto[20];
    fflush(stdin);
    gets(produto);
    fflush(stdin);
    printf("Preço do %s: R$", produto);
    float preco, desconto;
    fflush(stdin);
    scanf("%f", &preco);
    fflush(stdin);
    printf("Desconto: (%%) ");
    fflush(stdin);
    scanf("%f", &desconto);
    printf("O produto %s custava R$%.2f, mas com %.2f%% de desconto, passa a custar R$%.2f.", produto, preco, desconto, preco - (preco * desconto/100));
}