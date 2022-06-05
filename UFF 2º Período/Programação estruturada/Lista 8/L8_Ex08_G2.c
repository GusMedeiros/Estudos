#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int n, char* v){
    int i, end;

    for(end=n-1; end>0; end--){
        int troca=0;
        for(i=0; i<end; i++){
            if( v[i] > v[i+1] ){
                int temp = v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
                troca=1;
            }
        }
        if(!troca) return;
    }
}

void quick_sort(int n, char* v){
    int i, a=0, pivot=n-1;
    int troca = 0;

    for(i=0; i<n; i++){
        if( v[i] <= v[pivot] ){
            if(a<i){
                int temp = v[i];
                v[i]=v[a];
                v[a]=temp;
                troca=1;
            }
            a++;
        }
    }
    if(!troca) return;
    if(n>1){
        quick_sort(a, v);
        quick_sort(n-a, &v[a]);
    }
}

int comp_char(const void * c1, const void * c2){
    char a = *((char *) c1);
    char b = *((char *) c2);
    return a-b;
}


int main(void){
    int i, n=5;
    char letras[] = {'b', 'd', 'a', 'f', 'c'};

    printf("Vetor sem ordenacao: ");
    for(i=0; i<n; i++){
        printf("%c ",letras[i]);
    }
    printf("\n");

    printf("Bubble Sort\n");
    bubble_sort(n, letras);
    for(i=0; i<n; i++){
        printf("%c ",letras[i]);
    }
    printf("\n");

    printf("Quick Sort\n");
    quick_sort(n, letras);
    for(i=0; i<n; i++){
        printf("%c ",letras[i]);
    }
    printf("\n");

    printf("Funcao qsort\n");
    qsort(letras, n, sizeof(letras[0]), comp_char);
    for(i=0; i<n; i++){
        printf("%c ",letras[i]);
    }
    
    return 0;
}