#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;
struct prova {
    Aluno a; /* Aluno que fez a prova */
    float q1, q2, q3, q4; /* Nota em cada questao */
};
typedef struct prova Prova;

int compara(Prova* prova1, Prova* prova2){
    float nota_prova1 = 0, nota_prova2 = 0;
    nota_prova1 = prova1->q1 + prova1->q2 + prova1->q3 + prova1->q4;
    nota_prova2 = prova2->q1 + prova2->q2 + prova2->q3 + prova2->q4;
    if (nota_prova1 < nota_prova2) {
        return 1;
    }
    else if (nota_prova1 > nota_prova2){
        return 0;
    }
    else {
        int tamanho_menor_nome = (strlen(prova1->a.nome) >= 
                                  strlen(prova2->a.nome)?strlen(prova2->a.nome):
                                  strlen(prova1->a.nome));
        for(int i = 0; i < tamanho_menor_nome; i++){
            if(prova1->a.nome[i] > prova2->a.nome[i]){ // se a letra do nome 1 vier depois no alfabeto
                return 1;
            }
        }
    }
    return 0;


}

void troca(Prova** elemento1, Prova** elemento2){
    // elemento1 é o endereço do elemento i do vetor, que é um ponteiro de provas.
    // o que é desejado: que esse elemento i, ponteiro de provas, aponte para outra prova.
    Prova* auxiliar = *elemento1; // "backup" da prova 1
    *elemento1 = *elemento2; // fazendo &v[i] apontar para a prova 2
    *elemento2 = auxiliar; // fazendo &v[i+1] apontar para a prova 1

}


void ordena(int n, Prova** v) // v é um vetor de ponteiros de provas
{
    int fim,i;
    for(fim=n-1; fim>0; fim--){
        for(i=0; i<fim; i++){
            if(compara(v[i],v[i+1]))
                troca(&v[i],&v[i+1]); // v[i] é um ponteiro de prova. &v[i] é o endereço desse ponteiro.
        }
    }
}
// Essa função ordena o vetor em ordem decrescente de nota da prova --- que equivale à soma das
// notas das quatro questões ---, com desempate pela ordem alfabética do nome do aluno. Por
void main() {
    int qtdprovas;
    printf("Insira a quantidade de provas a serem ordenadas: ");
    scanf("%d", &qtdprovas);

    Prova** vetor = (Prova**) malloc(sizeof(Prova*) * qtdprovas);
    for(int i = 0; i < qtdprovas; i++){    
        vetor[i] = (Prova*) malloc(sizeof(Prova));
        printf("Insira o nome do(a) aluno(a): ");
        fflush(stdin);
        gets(vetor[i]->a.nome);
        fflush(stdin);
        printf("Insira a nota 1 de %s: ", vetor[i]->a.nome);
        scanf("%f",&vetor[i]->q1);
        fflush(stdin);
        printf("Insira a nota 2 de %s: ", vetor[i]->a.nome);
        scanf("%f",&vetor[i]->q2);
        fflush(stdin);
        printf("Insira a nota 3 de %s: ", vetor[i]->a.nome);
        scanf("%f",&vetor[i]->q3);
        fflush(stdin);
        printf("Insira a nota 4 de %s: ", vetor[i]->a.nome);
        scanf("%f",&vetor[i]->q4);
    }

    ordena(qtdprovas, vetor);
    for(int i=0;i<qtdprovas;i++){
    printf("%f\n%s\n", vetor[i]->q1, vetor[i]->a.nome);
    }
}