char* abreviador(char nome[]) {
    int contanomes = 0;  
    for (int i=0; nome[i]!='\0'; i++){ 
        if (nome[i] >= 'A' && nome[i] <= 'Z') /* como "de", "da", "do", não podem ser maíusculos, isso os elimina, além de
        achar o início de cada nome de uma vez só. */
        {
            nome[contanomes] = nome[i];
            nome[contanomes+1] = '.';
            contanomes += 2;
        }
    }
    nome[contanomes] = '\0';
    return nome;
}

#include <stdio.h>
void main() {
    char nome[] = "Fulano da Silva Pereira Pinto";
    printf("%s", abreviador(nome));
}
