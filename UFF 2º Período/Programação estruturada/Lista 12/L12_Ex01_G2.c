#include <stdio.h>

int mdc_recursiva(int a, int b) {
    printf("\n%d e %d", a, b);

    if (a % b == 0){
        return b;
    }
    return mdc_recursiva (b, a % b);
}

int main() {
    int a=32, b=18;

    printf("\nResultado=%d",mdc_recursiva(a, b));

    printf("\n\nSera impresso o MDC de 32 e 18");
    printf("\nA funcao imprime os valores em que serao testados o MDC, encontrara o resto da divisao entre esses dois valores e chamara a funcao novamente. Somente vai sair da funcao quando a for divisivel por b.");

    return 0;
}
