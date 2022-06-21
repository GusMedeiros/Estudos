#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
    float info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o pr?ximo elemento */
};
typedef struct elemento Elemento;

Elemento *lista_insere(Elemento *listaf, float info){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo ==NULL){exit(1);}
    novo->info = info;
    novo->prox = listaf;
    return novo;
}

Elemento* filtra(Elemento *listaf, float min, float max){
    Elemento* ant = NULL;
    Elemento *p = listaf;
    while(p!= NULL && p->info >= min && p->info<=max){
        ant = p;
        p = p->prox;
    }
    if(p== NULL){
        return listaf;
    }
    if(ant == NULL){
        listaf = p->prox;
    } else{
        ant->prox = p->prox;
    }
    listaf = filtra(listaf,min,max);
    free(p);
    return listaf;
}

void imprime(Elemento *listaf){
    Elemento *p;
    for(p=listaf;p!=NULL;p = p->prox){
        printf("%.1f\n", p->info);
    }
}

int main(){
    Elemento* lista =   NULL;
    float minimo_lista, maximo_lista;

    lista = lista_insere(lista, 1);
    lista = lista_insere(lista, 250);
    lista = lista_insere(lista, 500);
    printf("Valores da lista: \n");
    imprime(lista);

    printf("valor minimo da lista: ");
    scanf("%f", &minimo_lista);

    printf("valor maximo da lista: ");
    scanf("%f", &maximo_lista);

    lista = filtra(lista,minimo_lista,maximo_lista);

    printf("Lista final:\n");
    imprime(lista);
    return 0;
}