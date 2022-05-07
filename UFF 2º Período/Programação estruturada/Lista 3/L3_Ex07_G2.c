#include <stdio.h>

int main() {
    int *pti;
    int veti[]={10,7,2,6,3};
    pti = veti;
    printf("%d \n", *pti);
    printf("Verdadeiro. *pti Corresponde ao conteudo da posicao 0 do vetor \n\n ");

    printf("%d \n", *(pti+2));
    printf("Verdadeiro. *(pti+2) Corresponde ao conteudo da posicao 2 do vetor \n\n ");

    printf("%d \n", pti[4]);
    printf("Verdadeiro. pti[4] Corresponde ao conteudo da posicao 4 do vetor \n\n ");

    printf("%d \n", pti[1]);
    printf("Falso. pti[1] Corresponde ao conteudo da posicao 1 do vetor \n\n ");

    printf("%d \n", *(veti+3));
    printf("Verdadeiro. *(veti+3) Corresponde ao conteudo da posicao 3 do vetor \n\n ");

    return 0;
}
