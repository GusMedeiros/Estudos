#include<stdio.h>
#include<locale.h>
void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Insira um ano e direi se é bissexto: ");
    int ano;
    fflush(stdin);
    scanf("%d", &ano);
    int bissexto;
    if (ano % 100 != 0 && ano % 4 == 0 || ano % 400 == 0){
        bissexto = 1;
    }
    else {
        bissexto = 0;
    }
    printf("O ano %d %s bissexto.", ano, bissexto==1?"é":"não é");

}
