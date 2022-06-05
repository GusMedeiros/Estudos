#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct data {
int dia;
int mes;
char nomeMes[12];
} Data;


int main()
{
Data aniversarios[3] = { {5,1,"JANEIRO"},
{4,2,"FEVEREIRO"},{10,3,"MAIO"} };
int a;
Data *p_dt;
p_dt=&aniversarios[2];
printf("Nome do mes %d eh %s.", p_dt->mes, p_dt->nomeMes);
strcpy(p_dt->nomeMes, "MARÇO");
printf("\nNumero de letras = %d", strlen(p_dt->nomeMes));
// O segundo printf vai imprimir o numero de letras do mes referente a string da struct, nesse caso maior=5
// p_dt2 não foi declarado como ponteiro na linha 19
Data *p_dt2 = (Data *) malloc(sizeof(Data));
p_dt2 = &aniversarios[0];
}