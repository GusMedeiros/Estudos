#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
    int info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o pr?ximo elemento */
};
typedef struct elemento Elemento;

Elemento *lista_inserir(Elemento *listaf, float info){

    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo==NULL)
        exit(1);
    novo->info = info;
    novo->prox = listaf;
    return novo;
}

Elemento* copia(Elemento* listaf){

    Elemento* listCopy = NULL;
    Elemento* copia_lista = NULL;
    Elemento *p = listaf;

    for(p=listaf;p!=NULL;p = p->prox){
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        novo->info = p->info;
        novo->prox = listCopy;
        listCopy = novo;
    }
    for(p=listCopy;p!=NULL;p = p->prox){
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        novo->info = p->info;
        novo->prox = copia_lista;
        copia_lista = novo;
    }

    return copia_lista;
}

void imprimir(Elemento *listaf){

    Elemento *p;

    for(p=listaf;p!=NULL;p = p->prox){
        printf("%.d\n", p->info);
    }
}

int main(){

    Elemento* lista = NULL;

    lista = lista_inserir(lista, 1);
    lista = lista_inserir(lista, 250);
    lista = lista_inserir(lista, 500);

    printf("Lista: \n");
    imprimir(lista);
    printf("Copia: \n");
    imprimir(copia(lista));
    return 0;
}