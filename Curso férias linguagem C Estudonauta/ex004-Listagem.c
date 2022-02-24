#include <stdio.h>
#include <locale.h>

char nome1[20];
char nome2[20];
char nome3[20];

int idade1;
int idade2;
int idade3;

char sexo1;
char sexo2;
char sexo3;

float nota1;
float nota2;
float nota3;

void main() {
    printf("Cadastrando a primeira pessoa:\n");
    printf("------------------------------\n");
    printf("NOME: ");
    fflush(stdin);
    gets(nome1);
    fflush(stdin);

    printf("SEXO: [M/F] ");
    sexo1 = getchar();
    fflush(stdin);
        printf("NOTA: ");
    scanf("%f", &nota1);
    fflush(stdin);
    // segunda pessoa

    printf("\nCadastrando a segunda pessoa:\n");
    printf("------------------------------\n");
    printf("NOME: ");
    
    gets(nome2);
    fflush(stdin);

    printf("SEXO: [M/F] ");
    sexo2 = getchar();
    fflush(stdin);

    printf("NOTA: ");
    scanf("%f", &nota2);
    fflush(stdin);
    // terceira pessoa
    
    printf("\nCadastrando a terceira pessoa:\n");
    printf("------------------------------\n");
    printf("NOME: ");
    
    gets(nome3);
    fflush(stdin);

    printf("SEXO: [M/F] ");
    sexo3 = getchar();
    fflush(stdin);

    printf("NOTA: ");
    scanf("%f", &nota3);
    fflush(stdin);
    // listagem
    printf("\nListagem Completa\n");
    printf("------------------------------------\n");
    printf("NOME%16s SEXO  NOTA\n", "");
    printf("%-20s %3c %6.1f\n", nome1, sexo1, nota1);
    printf("%-20s %3c %6.1f\n", nome2, sexo2, nota2);
    printf("%-20s %3c %6.1f\n", nome3, sexo3, nota3);
    printf("------------------------------------\n");


}