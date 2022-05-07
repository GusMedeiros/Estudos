#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){

    int numeroSorteado, tentativasDeAcerto = 0, palpite;

    srand(time(NULL));


    numeroSorteado = rand() % 100;//

    do{
        printf("Digite o seu palpite de numero sorteado: ");
        scanf("%d", &palpite);
        if(palpite != numeroSorteado){
                tentativasDeAcerto++;
                if(palpite > numeroSorteado){
                    printf("O numero sorteado e menor que seu palpite\n");

                }else{
                    printf("O numero sorteado e maior que seu palpite\n");
                }
        }
    }while(palpite != numeroSorteado);

    tentativasDeAcerto++;
    printf("Quantidade de tentativas até o acerto do numero sorteado: %d", tentativasDeAcerto);


    return 0;
}
