#include <stdio.h>
#define maximo 30

 int main(void)
 {
    int m, n, i, j,
    m1[maximo][maximo], m2[maximo][maximo], m3[maximo][maximo];
    printf("Digite qual a ordem da sua matriz: \n");
    scanf("%d", &m);
    scanf("%d", &n);
    if (m < maximo && n < maximo){
        for (i = 0; i < m; i = i + 1)
            for (j = 0; j < n; j = j + 1){
                printf("Digite o valor [%d][%i] da matriz 1: ", i+1, j+1);
                scanf("%d", &m1[i][j]);
            }
         for (i = 0; i < m; i = i + 1)
             for (j = 0; j < n; j = j + 1){
                printf("Digite o valor [%d][%i] da matriz 2: ", i+1, j+1);
                scanf("%d", &m2[i][j]);
             }
         printf("\n");
         for (i = 0; i < m; i = i + 1)
         {
             for (j = 0; j < n; j = j + 1)
             {
                 m3[i][j] = m1[i][j] + m2[i][j];
                 printf("%3d", m3[i][j]);
             }
             printf("\n");
}
       }
    else printf("Matriz excessivamente grande!\n");
    return 0;
   }
