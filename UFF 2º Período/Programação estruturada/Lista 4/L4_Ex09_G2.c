#include <stdio.h>
int* ler_vet();
void listar_vet(int* vet);
int pesquisar(int* vet);
void trocar(int* vet);

int main()
{
    int *vet, i;
    vet = ler_vet();
    printf("\n");
    listar_vet(vet);
    pesquisar(vet);
    printf("\n");
    trocar(vet);
    printf("Apos a troca dos valores:\n");
    listar_vet(vet);
    
    return 0;
}

int* ler_vet(){
    int i;
    static int vet[7];
    
    for(i = 0; i < 7; i++){
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &vet[i]);
    }
    
    return vet;
}

void listar_vet(int* vet){
    int i;
    for(i = 0; i < 7; i++){
        printf("Posicao[%d]: %d\n", i, vet[i]);
    } 
}

int pesquisar(int* vet){
    int i, num, posicao;
    posicao = -1;
    printf("\nDigite o valor que deseja pesquisar: "); 
    scanf("%d", &num);
    for(i = 0; i < 7; i++){
        if(vet[i] == num){
            printf("\nO valor digitado foi encontrado na posicao[%d]\n", i);
            posicao = i;
        }
    }
    if(posicao == -1){
        printf("\nO valor digitado nao foi encontrado\n");
    }

    return posicao;
}

void trocar(int* vet){
    int i; 
    for(i = 1; i < 7; i++){
        vet[i] = vet[i-1] + vet[i];    
    }
}