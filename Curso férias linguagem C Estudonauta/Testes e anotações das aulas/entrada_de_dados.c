#include<locale.h>
#include<stdio.h>

void main() {
    // declara��es
    int inteiro;
    float real;
    char caractere;
    char string;
    // linguagem
    setlocale(LC_ALL, "Portuguese");
    // entradas
    printf("Digite um n�mero inteiro: ");
    fflush(stdin);
    scanf("%d", &inteiro);
    printf("Digite um n�mero real: ");
    fflush(stdin);
    scanf("%f", &real);
    printf("Digite um caractere solto: ");
    fflush(stdin);
    scanf("%c", &caractere);
    printf("Digite uma string:\n");
    // scanf("%s", &string);
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %f\n", real);
    printf("Caractere: %c\n", caractere);
    // printf("String : %s", string);

}