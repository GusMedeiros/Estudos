#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CamelCase (char *s){
    int controle=0, i=0, j=0;
    char saida[50];

    while (s[i]!='\0'){
        if (s[i]==' '){
            i++;
            saida[j]=s[i]-32;
        }else{
            saida[j]=s[i];
        }
        i++;
        j++;
    }

    printf("Frase transformada: %s", saida);
}

int main() {
    char frase[50];

    printf("Digite a frase: ");
    scanf("%[^\n]s",&frase);

    CamelCase (frase);

    return 0;
}
