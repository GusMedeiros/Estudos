#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
}Aluno;

typedef struct Materia {
    Aluno *V; // Armazena a informa��o de n alunos !!
    float media[5]; // Armazena as 5 m�dias do ano.
    int nAlunos // N�mero de alunos matriculados no curso.
}Materia;


Aluno* fillAluno(){
    char nome[100];
    int mat;
    float notas[5];


    printf("\nDigite o nome do aluno: ");
    scanf("%s", nome);

    printf("Digite a matricula: ");
    scanf("%d", &mat);

    for (int i=0; i<5;i++){
        printf("Digite a nota %d: ", i+1);
        scanf("%f", &notas[i]);
    }

    Aluno *estudante=(Aluno*)malloc(sizeof(Aluno));
    if (estudante==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }
    float *notas2=(float*)malloc(5*sizeof(float));
    if (notas2==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }
    estudante->vNotas=notas2;

    strcpy(estudante->nome, nome);
    estudante->matricula=mat;
    for (int j=0;j<5;j++){
        estudante->vNotas[j]=notas[j];
    }
    return estudante;

}


Materia * fillMateria(int numAlunos){
    Materia *disciplina=(Materia*)malloc(sizeof(Materia));
    if (disciplina==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }
    Aluno *vetor_alunos=(Aluno*)malloc(numAlunos*sizeof(Aluno));
    if (vetor_alunos==NULL) {
        printf("Falta memoria\n");
        exit(1);
    }

    disciplina->nAlunos=numAlunos;

    for (int i=0; i<numAlunos;i++){
        vetor_alunos[i]= *fillAluno();
    }
    disciplina->V=vetor_alunos;

    return disciplina;
}


void mediaMateria(Materia *m1){
    float soma;
    for (int j=0;j<5;j++){
        soma=0;
        for (int i=0; i< m1->nAlunos ;i++){
            soma=soma+(m1->V[i].vNotas[j]);
        }
        m1->media[j]=soma/(m1->nAlunos);
    }
}


void mostraMateria(Materia *m1){
    printf("\n--------------------------------------------------------\n");
    printf("\nNumero de alunos na materia: %d", m1->nAlunos);

    for (int i=0; i < m1->nAlunos; i++){
        printf("\n\nNome: %s", m1->V[i].nome);
        printf("\nMatricula: %d", m1->V[i].matricula);
        for (int j=0;j<5;j++){
            printf("\nNota %d: %.2f",j, m1->V[i].vNotas[j]);
        }
    }
    printf("\n\n--------------------------------------------------------\n\n");
    for (int j=0;j<5;j++){
        printf("Media da turma na prova %d: %.2f\n", j+1, m1->media[j]);
    }
}


int main(){
    Materia *m1;
    int numAlunos;

    printf("\nDigite a quantidade de alunos na materia: ");
    scanf("%d", &numAlunos);

    m1 = fillMateria(numAlunos);
    mediaMateria(m1);
    mostraMateria(m1);

    return 0;
}
