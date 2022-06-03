#include <stdio.h>
#define L 3
#define C 3


int main (){
    int mat[L][C], soma[L]={};

    for (int i=0; i<L; i++){
        for (int j=0; j<C; j++){
            printf("Digite o elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");

    for (int i=0; i<L; i++){
        for (int j=0; j<C; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<L; i++){
        for (int j=0; j<C; j++){
            soma[i]=soma[i]+mat[i][j];
        }
        printf("%d ", soma[i]);
    }

    for (int i=0; i<L-1; i++){

        if (soma[i]!=soma[i+1]){
            printf("\nA soma dos elementos das linhas sao diferentes.");
            return 0;
        }
    }

    printf("\nA soma dos elementos das linhas sao iguais.");

    return 0;
}
