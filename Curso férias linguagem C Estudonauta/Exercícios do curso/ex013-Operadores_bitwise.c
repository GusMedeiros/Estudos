# include <stdio.h>
# include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    int primeiro, segundo;
    printf("Digite o primeiro valor: ");
    fflush(stdin);
    scanf("%d", &primeiro);
    printf("Digite o segundo valor: ");
    fflush(stdin);
    scanf("%d", &segundo);
    printf("-------- OPERA��ES BITWISE ---------\n");
    int resultado = primeiro & segundo;
    printf("Calculando %d & %d � igual a %d\n", primeiro, segundo, resultado);
    resultado = primeiro | segundo;
    printf("Calculando %d | %d � igual a %d\n", primeiro, segundo, resultado);
    resultado = primeiro ^ segundo;
    printf("Calculando %d ^ %d � igual a %d\n", primeiro, segundo, resultado);
    
}