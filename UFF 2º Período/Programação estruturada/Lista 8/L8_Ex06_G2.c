
#include <stdio.h>
#define L 8
#define C 8

int main (){
    int mat[L][C], peao=0, cavalo=0, torres=0, bispos=0, reis=0, rainhas=0, vazio=0;

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
            if (mat[i][j]==1)
                peao++;
            else if (mat[i][j]==2)
                cavalo++;
            else if (mat[i][j]==3)
                torres++;
            else if (mat[i][j]==4)
                bispos++;
            else if (mat[i][j]==5)
                reis++;
            else if (mat[i][j]==6)
                rainhas++;
            else if (mat[i][j]==0)
                vazio++;
        }
    }

    printf("\nSoma total de peoes e bispos: %d", peao+bispos);
    printf("\nQuantidade de posicoes sem peca: %d", vazio);
    printf("\nQuantidade de peoes: %d", peao);
    printf("\nQuantidade de cavalos: %d", cavalo);
    printf("\nQuantidade de torres: %d", torres);
    printf("\nQuantidade de bispos: %d", bispos);
    printf("\nQuantidade de reis: %d", reis);
    printf("\nQuantidade de rainhas: %d", rainhas);


    return 0;
}

