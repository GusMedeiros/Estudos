#include <stdio.h>

int main(){
    printf("Escreva uma das 4 opcoes: +, -, *, / \n");
    char a,d,e,f,g;
    int b, c, soma, sub, multi, div;
    scanf("%c", &a);
    printf(" Escreva dois numeros: \n");
    scanf("%d %d", &b, &c);
    d = '+';
    e = '-';
    f = '*';
    g = '/';
    if(a==d){
         soma = b+c;
        printf("%d", soma);
        return 0;
    }
    if(a==e){
        sub = b-c;
        printf("%d", sub);
        return 0;
    }
    if(a==f){
        multi = b*c;
        printf("%d", multi);
        return 0;
    }
    if(a==g){
        div = b/c;
        printf("%d", div);
        return 0;
    }
}
