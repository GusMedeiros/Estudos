#include<stdio.h>
#include <string.h>
#include <stdlib.h>
void main() {
    char arquivo[] = "L10_Ex07_G2 copy.c";
    char arquivotemp[] = "arquivo.temp";
    FILE *f = fopen(arquivo, "r");
    FILE *ftemp = fopen(arquivotemp, "w");
    if (f == NULL|| ftemp == NULL) exit(-1);
    char c3, c2 = '\0', c1 = '\0';
    printf("entering while");
    int ignorar = 0;
    while (c1 != EOF) {
        c3 = fgetc(f);
        printf("a");
        if (c2 == '/' && c1 == '/'){
            ignorar = 1;
        }
        else if (c1 == '\n'){
            ignorar = 0;
        }
        if (c1 == '\n' && c2 == '/' && c3 == '/'){
            ignorar = 1;
        }
        if (!ignorar && c1 != '\0') {
            putc(c1, ftemp);
        }
        c1 = c2;
        c2 = c3;
    }
    fclose(f); fclose(ftemp);
    remove(arquivo);
    rename(arquivotemp, arquivo);
}