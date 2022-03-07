#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("======== TABELA DE PREÇOS ========\n");
    printf("Viagens até 200 Km\tR$0.50/Km\n");
    printf("A partir de 200 Km\tR$0.35/Km\n");
    printf("----------------------------------\n");
    printf("Distância total da viagem, em Km: ");
    float distancia;
    fflush(stdin);
    scanf("%f", &distancia);
    printf("Uma viagem de %.1f Km vai custar R$", distancia);
    if (distancia < 200) {
        printf("0,50/Km\n");
        printf("Valor Total: R$%.2f.", distancia * 0.5);
        }
    else {
        printf("0,35/Km\n");
        printf("Valor Total: R$%.2f.", distancia * 0.35);
        }
}
