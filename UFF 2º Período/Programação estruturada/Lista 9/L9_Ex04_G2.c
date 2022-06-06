#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atribui(char **nomes, int indice, char *nome);
char *get_sobrenome(char *nome);
int main()
{
	int i;
	char **nomes;
	char *sobrenome;
	nomes = (char **) malloc(MAX*sizeof(char *));

	for ( i=0 ; i<MAX ; i++) {
		nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
	}
	atribui(nomes, 0, "Fulano Silva"); 
	atribui(nomes, 1, "Maria do Carmo");
	atribui(nomes, 2, "Beltrano Belmonte"); 
	atribui(nomes, 3, "Pedro dos Santos");

	for (i=0 ; i<MAX ; i++) {
		sobrenome = get_sobrenome(nomes[i]);
		printf("\n%s ", sobrenome);
		printf(" %d",strlen(sobrenome)>5?i:0); // 2o printf -> o operador ternário checa se o tamanho do sobrenome é maior 
        // que 5. caso seja, printa o índice do nome atual, caso não, printa zero.
	}

	printf("\n%c", nomes[0][3]); // 3o printf
	// imprime o indice 3 do 1 elemento de nomes, nesse caso imprime o primeiro 'a' de "Fulano Silva"
	return 0;
}

void atribui(char **nomes, int indice, char *nome)
{
	strcpy(nomes[indice], nome);
}

char *get_sobrenome(char *nome)
{
	int i, j;
	for(i=0;i<strlen(nome);i++){	
		if(nome[i]==' '){
			j=i+1;
		}
	}
    int tamanho_sobrenome = strlen(nome) - j;
    char* sobrenome = (char*) malloc(sizeof(char) * tamanho_sobrenome);
	strcpy(sobrenome, &nome[j]);
	return sobrenome;
}