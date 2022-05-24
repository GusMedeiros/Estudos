#include <stdio.h>

#define TAM 5

int main(){
int i;
float vet1[TAM]; // Armazena 20 inteiros;
float vet2[TAM]; // Armazena outros 20 inteiros;
char operacoes[TAM]; //Armazena as opera��es a serem feitas (+, -, * e /);
float resultados[TAM]; //Resultado das opera��es.

for ( i=0; i<TAM ; i++ ){
printf(" Diga vetor 1 [%d]: ",i);
scanf("%f",&vet1[i]);
}

for ( i=0; i<TAM ; i++ ){
printf(" Diga vetor 2 [%d]: ",i);
scanf("%f",&vet2[i]);
}

for ( i=0; i<TAM ; i++ ){
printf(" Diga Operacoes [%d]: ",i);
fflush(stdin);
scanf("%c",&operacoes[i]);
}

for ( i=0; i<TAM ; i++ ){
switch(operacoes[i]){
case '+': resultados[i] = vet1[i] + vet2[i]; break;
case '-': resultados[i] = vet1[i] - vet2[i]; break;
case '*': resultados[i] = vet1[i] * vet2[i]; break;
case '/': resultados[i] = vet1[i] / vet2[i]; break;
}
printf("\n Vet1[%.2f] [%c] Vet2[%.2f] = %.2f",vet1[i],operacoes[i],vet2[i],resultados[i]);
}

return(0);
}

