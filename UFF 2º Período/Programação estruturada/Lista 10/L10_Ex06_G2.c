#include <stdio.h>
#include <stdlib.h>
void main() {
    char nome_arquivo[] = "teste00.txt";
    for (char c = '1'; c < '9' + 2; c++){
        if(c <= '9'){
            nome_arquivo[5] = '0';
            nome_arquivo[6] = c;

        }
        else if (c == '9' + 1){
            nome_arquivo[5] = '1';
            nome_arquivo[6] = '0';
        }
        FILE* f = fopen(nome_arquivo, "w");
        if(f == NULL) {
            printf("FALHA AO ABRIR ARQUIVO");
            exit(-1);
        }
        fputs("Texto do arquivo ", f);
        fputc(nome_arquivo[5], f);
        fputc(nome_arquivo[6], f);
        fclose(f);
    }
}