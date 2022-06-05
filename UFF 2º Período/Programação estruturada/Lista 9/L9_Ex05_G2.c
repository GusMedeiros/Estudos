#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct endereco {
char rua[100]; /* Nome da rua */
int numero; /* Numero do imovel */
} Endereco;


typedef struct notas {
float p1, p2, p3; /* Notas nas provas */
} Notas;


typedef struct aluno {
int mat; /* Matricula do aluno */
char nome[81]; /* Nome do aluno */
Notas nota; /* Notas nas provas */
Endereco *end; /* Endereco do aluno */
} Aluno;


Aluno ** alocaAlunos(int n);
void atribui(Aluno ** a, int indice, int matricula, char *nome, float
nota1, float nota2, float nota3, char *nomeRua, int numero);

void main(){
Aluno **alunos;
alunos = alocaAlunos(3);
atribui(alunos,0,10,"Um",1,1,1,"Getulio Vargas",100);
atribui(alunos,1,20,"Dois",8,8,8,"Amaral Peixoto",200);
atribui(alunos,2,30,"Tres",9,9,9,"Ouro Verde",300);
printf("a");
}

Aluno** alocaAlunos(int n){
    Aluno** vetor_alunos = (Aluno**) malloc(sizeof(Aluno*) * n);
    if (vetor_alunos == NULL){
        printf("Sem memoria para o vetor de aluno");
        exit(-1);
    }
    for(int i = 0; i < n; i++){
        vetor_alunos[i] = (Aluno*) malloc(sizeof(Aluno));
        if (vetor_alunos[i] == NULL){
            printf("Sem memoria para o ponteiro de aluno");
            exit(-1);
        }
        vetor_alunos[i]->end = (Endereco*) malloc(sizeof(Endereco));

    }
    return vetor_alunos;
}

void atribui(Aluno ** a, int indice, int matricula, char *nome, float
nota1, float nota2, float nota3, char *nomeRua, int numero){
    a[indice]->mat = matricula;
    int i;
    for (i = 0; nome[i] != '\0'; i++){
        a[indice]->nome[i] = nome[i];
    }
    a[indice]->nome[i+1] = '\0';
    a[indice]->nota.p1 = nota1;
    a[indice]->nota.p2 = nota2;
    a[indice]->nota.p3 = nota3;
    for (i = 0; nomeRua[i] != '\0'; i++){
        a[indice]->end->rua[i] = nomeRua[i];
    }
    a[indice]->end->rua[i+1] = '\0';
    a[indice]->end->numero = numero;
}