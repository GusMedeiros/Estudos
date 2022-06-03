#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maximo 20

int simetrica(){
    int m, n, i, j, contador=0,
    matriz[maximo][maximo], transposta[maximo][maximo];
    printf("Digite a quantidade de linhas da sua matriz: \n");
    scanf("%d",&m);
    printf("Digite a quantidade de colunas da sua matriz: \n");
    scanf("%d", &n);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Digite o elemento [%d][%d]: \n", i+1, j+1);
            scanf("%d",&matriz[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            transposta[j][i]=matriz[i][j];
        }
        printf(" \n");
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(transposta[i][j] == matriz[i][j]){
                contador++;
            }
        }
    }
    if(contador==m*n){
        printf("A matriz e simetrica. \n");
    }
    else{
        printf("A funcao nao e simetrica. \n");
    }
}
int main(){
    simetrica();
}
