#include <stdio.h>
#include <string.h>

int valida_mail(char *s);
	
int main(){
	int valido;
	char cadeiaS[64];
	printf("Digite o endereco local do email:");
	scanf("%s",cadeiaS);
	valido=valida_mail(cadeiaS);
	if(valido==0)
		printf("Invalido");
	if(valido==1){
		printf("Valido");
		printf("\n" "1");
	}
		
	return 0;
}

int valida_mail(char *s){
	int validof=1, cont=0;
	if((s[0]>=65)&&(s[0]<=90)||(s[0]>=97)&&(s[0]<=122))
		validof=1;	
	else{
		validof=0;
		return validof;
	}
	if(s[strlen(s)-1]==46){
		validof=0;
		return validof;
	}
	for (int i=0 ; s[i]!=0 ; i++){
		if ((s[i]==46)&&(s[i+1]==46)){
			validof=0;
			return validof;
		}
		if ((s[i]>=65)&&(s[i]<=90)||(s[i]>=97)&&(s[i]<=122)||(s[i]>=48)&&(s[i]<=57)){
			cont+=1;
		}
		if ((s[i]==45)||(s[i]==46)||(s[i]>=48)&&(s[i]<=57)||(s[i]==65)&&(s[i]>=90)||(s[i]==95)||(s[i]>=97)&&(s[i]<=122)){
			validof=1;
		}
		else{
			validof=0;
			return validof;
		}		
	}	
	if(cont<2){
		validof=0;
		return validof;
	}	
	return validof;		
	}	
