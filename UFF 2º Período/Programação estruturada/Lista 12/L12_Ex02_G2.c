#include <stdio.h>
#include <stdlib.h>

int somaimpar(int* vetor, int i, int vf);

int main(){
    int vetor[5]={1,2,3,4,5};
    int i=0,vf=0;
    vf = somaimpar(vetor, i, vf);
    printf("soma dos impares: %d",vf);


    return 0;
}

int somaimpar(int* vetor, int i, int vf){
 if(i>=5)return(vf);
    if (vetor[i]%2==1){
        vf+=vetor[i];
    }
    i++;
    somaimpar(vetor,i,vf);
}