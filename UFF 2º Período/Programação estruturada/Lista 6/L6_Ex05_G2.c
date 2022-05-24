#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * compara (char *frases);

int main(){

    char frase[20], *volta;
    int tamanho=0, i;

    printf("Digite a frase de apenas 20 caracters: ");
    gets(frase);
    tamanho=strlen(frase);
    volta=compara(frase);
    printf("\n");
    for(i=0; i<tamanho;i++){
        printf("%c", volta[ i ]);
    }
    return 0;
}
    char * compara (char *frases){

        int tamanho=strlen(frases);
        char *letra, i ;
        letra = (char*) malloc(tamanho*sizeof(char));

            for(i=0; i<tamanho; i++){
                if (frases [i] == 'Z'){
                    letra[i] = 'C';
                    continue;
                }
                if (frases [i] == 'X'){
                    letra[i] = 'A';
                    continue;
                }
                if (frases [i] == 'Y'){
                    letra[i] = 'B';
                    continue;
                }
                if(frases[ i ] == 'z'){
                    letra[ i ]='c';
                    continue;
                }
                if(frases[ i ] == 'y'){
                    letra[ i ]='b';
                    continue;
                }
                if(frases[ i ] == 'x'){
                    letra[ i ]='a';
                    continue;
                }
                if(frases[ i ]==' '){
                    letra[ i ]=' ';
                    continue;
                }
                else {
                    letra[ i ]=frases[ i ]+3;
                }
            }
    return letra;
}
