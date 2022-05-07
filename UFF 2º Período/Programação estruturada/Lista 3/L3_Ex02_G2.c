#include <stdio.h>

int main() {
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
    printf("%d\n", p);
    printf("p == &i correspondende ao endereco da variavel i \n\n");

    printf("%d\n", *p - *q);
    printf("*p - *q correspondende a soma do conteudo de p com q \n\n");

    printf("%d\n", **&p);
    printf("**&p correspondende ao conteudo de p \n\n");

    printf("%d\n", 3*-*p/(*q)+7);
    printf("3* - *p/(*q)+7 corresponde a 5,2 e foi arredondado para 6 \n\n");

    return 0;
}
