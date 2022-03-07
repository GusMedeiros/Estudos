#include <stdio.h>

int main() {
    int numeros_ordenados[3], numeros_originais[3], indice;
    fflush(stdin);
    scanf("%d %d %d", &numeros_originais[0], &numeros_originais[1], &numeros_originais[2]);
    indice = 0;
    while (indice < 3) {
        numeros_ordenados[indice] = numeros_originais[indice]; 
        indice ++;
    }
    indice = 0;
    int state_ordenado = 0;
    while (state_ordenado == 0) {
        state_ordenado = 1; indice = 0;
        while (indice < 2) {
            if (numeros_ordenados[indice] > numeros_ordenados[indice+1]) {
                int aux = numeros_ordenados[indice+1];
                numeros_ordenados[indice+1] = numeros_ordenados[indice];
                numeros_ordenados[indice] = aux;
                state_ordenado = 0;
            }
            indice ++;
        }
    }
    indice = 0;
    while (indice < 3) {
        printf("%d\n", numeros_ordenados[indice]);
        indice ++;
    }
    indice = 0;
    printf("\n");
    while (indice < 3) {
        printf("%d\n", numeros_originais[indice]);
        indice ++;
    }
    return 0;
}