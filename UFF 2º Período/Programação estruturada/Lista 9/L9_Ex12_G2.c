#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
typedef struct Livro {
int ano;
char titulo[100];
char autor[100];
int nVolume; // NÃºmero de exemplares de um dado livro.
float preco;
}Livro;

typedef struct Biblioteca {
Livro **V; // Armazena a informaÃ§Ã£o de n livros !!
int nLivros; // NÃºmero de livros existentes na biblioteca.
}Biblioteca;

Livro* fillLivro() {
    Livro* livro = (Livro*) malloc(sizeof(Livro));
    printf("Insira o ano do livro: ");
    scanf("%4d", &livro->ano);
    printf("Insira o título do livro: ");
    fflush(stdin);
    gets(livro->titulo);
    printf("Insira o autor do livro: ");
    fflush(stdin);
    gets(livro->autor);
    printf("Insira a qtd de exemplares do livro: ");
    scanf("%d", &livro->nVolume);
    printf("Insira o preco do livro: ");
    scanf("%f", &livro->preco);
    return livro;
}
Biblioteca* fillBiblioteca(int numLivros){
    Biblioteca* biblioteca = (Biblioteca*) malloc(sizeof(Biblioteca));
    biblioteca->nLivros = numLivros;
    biblioteca->V = (Livro**) malloc(sizeof(Livro*) * numLivros);
    for (int i = 0; i < numLivros; i++){
        printf("Livro %d:\n", i+1);
        biblioteca->V[i] = fillLivro();
    }
    return biblioteca;
}
void valorBiblioteca(Biblioteca *b1, int numLivros){
    float valor_total = 0;
    for (int i = 0; i < numLivros; i++){
        valor_total += b1->V[i]->preco * b1->V[i]->nVolume;
    }
    printf("O valor total da biblioteca é de: R$%.2f.\n", valor_total);
}
Livro* maiorBiblioteca(Biblioteca *b1, int numlivros){
    Livro* maior = b1->V[0];
    for (int i=1; i<numlivros; i++){
        if (b1->V[i]->preco > maior->preco)
            maior = b1->V[i];
    }
    return maior;
}
void main() {
    setlocale(LC_ALL, "Portuguese");
    Biblioteca* biblioteca = fillBiblioteca(2);
    valorBiblioteca(biblioteca, biblioteca->nLivros);
    Livro* livro_com_mais_exemplares = maiorBiblioteca(biblioteca, biblioteca->nLivros);
    printf("O livro com mais exemplares da biblioteca é o %s.\n", livro_com_mais_exemplares->titulo); 
}