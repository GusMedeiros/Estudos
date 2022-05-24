#include <stdio.h>
#include <string.h>

int main(){
	int contador=0, i;
	char palavra[40];
	printf("Digite sua palavra:");
	scanf("%s",palavra);
	printf("Primeira letra: %c \n", palavra[0]);
	for(i=0 ; palavra[i]!='\0'; i++){
		contador+=1;
	}
	printf("Ultima letra: %c \n", palavra[i-1]);
	printf("Quantidade de letras na palavra: %d \n", contador);
}