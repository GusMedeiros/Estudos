/* 
7. Modifique o programa anterior da seguinte forma:
a) Passo igual ao da questão 1.
b) Ao invés de calcular e imprimir na main as repetições, crie uma
função 'repeticao' para fazer esse trabalho. A função deve seguir o
protótipo
void repeticao(int *vet, int tam);
Onde 'vet' e 'tam' foram lidos no passo a).

- Exemplo de execução: idêntico ao anterior.
- Obs.: A impressão é feita dentro da função 'repeticao'.
*/

#include <stdio.h>
#include <stdlib.h>
void repeticao(int *vet, int tam){
    int compara = 0, valor = 0, verifica = 0;
for(int i=0;i<tam;i++){
    for(compara=i+1;compara<tam;compara++){
        if(vet[i]==vet[compara]){
            valor=vet[i];
            vet[compara]=rand();
            if(vet[i]==0){
                valor = 0;
                printf("%d",valor);
        }
        }
        }
    if(valor!=verifica || valor!=0){
      printf("%d, ",valor);
      valor = 0;
    }
    verifica = valor;
}
}
void main(){
   int i, tamanho;
   printf("Digite o tamanho do seu vetor: \n");
   scanf("%d", &tamanho);
   int *v = (int*) malloc(tamanho*sizeof(int));
   if(v==NULL){exit(1);}
   for(i=0;i<tamanho;i++){
        scanf("%d", &v[i]);
   }
   repeticao(v, tamanho);
   free(v);
}
