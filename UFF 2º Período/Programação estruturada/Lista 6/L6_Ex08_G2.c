#include <stdio.h>
#include <stdlib.h>
int* repeticao(int *vet, int tam, int *n){
    int* repetidos = (int*) malloc(sizeof(int) * tam);
    if (repetidos == NULL){
        exit(1);
    }
    int contador = 0;
    int compara = 0, valor = 0, verifica = 0;
    for(int i=0;i<tam;i++)
    {
        for(compara=i+1;compara<tam;compara++)
            {
            if(vet[i]==vet[compara])
            {
                valor=vet[i];
                vet[compara]=rand();
                if(vet[i]==0){
                    valor = 0;
                    repetidos[contador++] = valor;
            }
            }
            }
        if(valor!=verifica || valor!=0)
        {
        repetidos[contador++] = valor;
        valor = 0;
        }
        verifica = valor;
        
    }
    *n = contador;
    return repetidos;
}
void main(){
   int i, tamanho, resultado = 0;
   printf("Digite o tamanho do seu vetor: \n");
   scanf("%d", &tamanho);
   int *v = (int*) malloc(tamanho*sizeof(int));
   if(v==NULL){exit(1);}
   for(i=0;i<tamanho;i++){
        scanf("%d", &v[i]);
   }
   int *vetorfinal = repeticao(v, tamanho, &resultado);
    for(i=0; i < resultado - 1; i++){
        printf("%d, ", vetorfinal[i]);
    }
    printf("%d.", vetorfinal[i]);
   free(v);
}
