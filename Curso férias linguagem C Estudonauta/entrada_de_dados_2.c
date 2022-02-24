#include<stdio.h>
#include<locale.h>
char resp;
char string[15];
void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Insira um caractere: ");
    resp = getchar();
    printf("Você inseriu o caractere \"%c\"\n", resp);
    printf("Insira outro caractere: ");
    fflush(stdin);
    resp = getchar();
    printf("Você inseriu o caractere \"%c\"\n", resp);
    printf("Insira uma string: ");
    fflush(stdin);
    gets(string);
    printf("Você inseriu a string \"%s\"\n", string);

}