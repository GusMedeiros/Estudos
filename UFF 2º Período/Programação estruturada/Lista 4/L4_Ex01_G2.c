#include <stdio.h>
#define N 10
int main(){
    int vetOriginal[N], vetInvert[N];
    int i = 0, j = 0; // recomendo sempre iniciar com 0

    for(i = 0; i < N; i++){
        printf("Digite um número!\n");
        scanf("%d", &vetOriginal[i]);
    }
    i = 0;
    for(j = N-1; j >= 0; j-- ){
        vetInvert[i] = vetOriginal[j];
        i++;
    }
    printf("O vetor invertido e: ");
    for(i = 0; i < N; i++)
        printf("%d ", vetInvert[i]);
    printf("\n");
    return 0;
}
