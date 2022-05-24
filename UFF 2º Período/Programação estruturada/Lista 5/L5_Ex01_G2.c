#include <stdio.h>
#include <string.h>

int contador_vogal(char s[], int *p);

int main(){
    int x=0, *p;
    p = &x;
    char cadeiaS[64];
    printf("Digite sua string:");
    gets(cadeiaS);
    contador_vogal(cadeiaS, p);
    printf("%d vogais", x);
    return 0;
}

int contador_vogal(char s[], int *p){
    for (int i=0 ; s[i]!='\0' ; i++){
        if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')||(s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U'))
            *p+=1;
    }
}