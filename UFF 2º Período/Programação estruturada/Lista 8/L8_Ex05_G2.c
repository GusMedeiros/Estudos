#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maximo 20

//*fun��o que retorna a soma das duas matrizes*//
int soma(int tamanho){
    int i, j, matriz_1[maximo][maximo], matriz_2[maximo][maximo];
    for(i=0;i<tamanho;i++){
            for(j=0;j<tamanho;j++){
                printf("Digite o elemento da linha %d coluna %d da matriz 1 : ", i+1, j+1);
                scanf("%d", &matriz_1[i][j]);
            }
    }
    for(i=0;i<tamanho;i++){
            for(j=0;j<tamanho;j++){
                printf("Digite o elemento da linha %d coluna %d da matriz 2: ", i+1, j+1);
                scanf("%d", &matriz_2[i][j]);
            }
    }
    printf("A matriz soma e: \n");
    for(i=0;i<tamanho;i++){
            for(j=0;j<tamanho;j++){
                    printf("%d ", matriz_1[i][j] + matriz_2[i][j]);
            }
        printf("\n");
    }
    diagonais(tamanho, matriz_1, matriz_2);
    produto(tamanho, matriz_1, matriz_2);
}
//*Fun��o que retorna a soma das diagonais de cada uma das matrizes//
int diagonais(int tamanho, int matriz[maximo][maximo],int matriz1[maximo][maximo]){
    int i, j, somar=0, somar2=0;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            if(i==j){
                somar2 += matriz1[i][j];
                somar += matriz[i][j];
            }
        }
    }
    for(i=0;i<tamanho;i++){
        somar2 += matriz1[i][tamanho-1-i];
        somar += matriz[i][tamanho-1-i];
    }
    printf("\nA soma das diagonais da primeira matriz e: %d \n" , somar);
    printf("A soma das diagonais da segunda matriz e: %d \n" , somar2);
}

int produto(int tamanho, int matriz[maximo][maximo], int matriz1[maximo][maximo]){
    int i, j, matriz_produto[maximo][maximo], somaproduto, k;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            somaproduto = 0;
            for(k=0;k<tamanho;k++) somaproduto+= matriz[i][k]*matriz1[k][j];
            matriz_produto[i][j] = somaproduto;
        }
    }
    printf("A matriz produto e: \n");

    for(i=0;i<tamanho;i++){
            for(j=0;j<tamanho;j++){
                    printf("%d ", matriz_produto[i][j]);
            }
    printf("\n");
    }
}

int main(){
    int tamanho;
    printf("Digite a ordem das matrizes: \n");
    scanf("%d", &tamanho);
    soma(tamanho);
}
