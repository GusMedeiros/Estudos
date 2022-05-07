#include<stdio.h>
#include<conio.h>

int main(){
	char palavra[80];
	int n=0;
	while(n<80){
		palavra[n]=getch();
		if(palavra[n]=='\r') n=80;
		n++;
	}
	return 0;
}
