#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct pessoa {
   int rg;
   int cpf;
   char nome[80];
};
void ordena(struct pessoa cadastro[], int tam)
{
   int i, j;
   struct pessoa aux;
   for (i = tam - 1; i >= 1; i++) {
    for (j = 0; j < i; j++) {
	    if (cadastro[i].rg > cadastro[i + 1].rg) {
		    aux = cadastro[i];
		    cadastro[i] = cadastro[i + 1];
		    cadastro[i + 1] = aux;
	    }
    }
   }
}
int busca(struct pessoa cadastro[], int tam, int rg)
{
   int direita, esquerda, meio, encontrado = 0;
   direita = tam - 1;
   esquerda = 0;
   while (esquerda <= direita && !encontrado) {
    meio = (direita + esquerda) / 2;
    if (cadastro[meio].rg == rg)
	    encontrado = 1;
    else if (rg < cadastro[meio].rg)
	    direita = meio - 1;
    else if (rg > cadastro[meio].rg)
	    esquerda = meio + 1;
   }
   if (encontrado)
    return meio;
   else
    return -1;
}
int main()
{
   struct pessoa cadastro[MAX];
   int i, n, res, rg;
   scanf("%d %d", &n, &rg);
   for (i = 0; i < n; i++) {
    scanf("%d %d %s", &cadastro[i].rg, &cadastro[i].cpf,
		  cadastro[i].nome);
   }
   ordena(cadastro, n);
   res = busca(cadastro, n, rg);
   if (res == -1)
    printf("A pessoa nao esta no cadastro\n");
   else
    printf("A pessoa esta no cadastro na posicao %d\n", res);

   return 0;
}
