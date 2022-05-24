#include <stdio.h>
#include <stdlib.h>

void main(){
   int i, compara = 0, tamanho, valor = 0, verifica=0;
   printf("Digite o tamanho do seu vetor: \n");
   scanf("%d", &tamanho);
   int *v = (int*) malloc(tamanho*sizeof(int));
   if(v==NULL){exit(1);}
   for(i=0;i<tamanho;i++){
        scanf("%d", &v[i]);
   }
   for(i=0;i<tamanho;i++){
    for(compara=i+1;compara<tamanho;compara++){
        if(v[i]==v[compara]){
            valor=v[i];
            v[compara]=rand();
            if(v[i]==0){
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
