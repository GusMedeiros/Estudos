#include <stdio.h>
int main(){
    int a,b,c, maior, menor, media, par, par1, par2, d, e, f;
    par = 1;
    par1 = 1;
    par2 = 1;
    scanf("%d %d %d", &a, &b, &c);
    if (a>b&&a>c) {
        maior = a;
    }
    if (b>a&&b>c){
        maior = b;
    }
    if (c>a&&c>b){
        maior = c;
    }
    if (a<b&&a<c) {
        menor = a;
    }
    if (b<a&&b<c){
        menor = b;
    }
    if (c<a&&c<b){
        menor = c;
    }
    media = (a+b+c)/3;
    if(a%2 == 0){
        par1 = a;
    }
    if(b%2 == 0){
        par2 = b;
    }
    if(c%2 == 0){
        par = c;
    }
    printf(" Maior: %d \n Menor: %d \n Pares: ", maior, menor);
    if(par != 1){
        printf("%d ", par);
    }
    if(par1 != 1){
        printf("%d ", par1);
    }
    if(par2 != 1){
        printf("%d ", par2);
    }
    printf("\n Media: %d", media);
}