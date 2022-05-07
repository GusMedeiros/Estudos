#include <stdio.h>


int main() {
    int i=5, *p;
    p = &i;
    printf("%x %d %d \n", p, *p+2, 3**p);

    printf("p correponde ao endereco da variavel i e sera impresso na base hexadecimal. Se o endereco de i fosse 4094 seria impresso ffe \n");
    printf("*p +2 correponde ao conteudo do endereco i somado com 2\n");
    printf("3**p correponde a multiplicacao do conteudo do endereco i por 3");
    return 0;
}
