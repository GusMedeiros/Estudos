#include <stdio.h>
#include <string.h>

int main(){
	int num=2;
	char dados[20]="Joao,18,Rj";
	char *t, idade[3];
	// função strtok divide uma string em substrings
	t = strtok(dados,",");
	printf("Nome: %s\n",t);
	//passamos primeiro a variavel da string e depois o metodo de separação
  	
	t=strtok(NULL,",");
	
	//a função continua de onde parou e separa novamente
  
	//Função strncpy copia uma string para um destino com memoria certa e o \0 deve ser adicionado manualmente
	
	strncpy(idade, t, num);
	idade[num]='\0';
	printf("Idade: %s\n",idade);
  
	t=strtok(NULL,",");
	char cidade[10]="Rj";
	if (strcmp (t, cidade)==0)
	printf("Carioca");
	//Função strcmp compara strings e se forem iguais retorna 0
  
  	return(0);
}