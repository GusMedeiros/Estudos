#include <stdio.h>
#include <string.h>

int main(){
	int contador=0, i;
	char texto[20];
	printf("Digite seu texto:");
	gets(texto);
	
	for(i=strlen(texto)-1 ; i>=0 ; i--){
		printf("%c", texto[i]);
	}
	return 0;
}
