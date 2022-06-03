#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char nome[80];
	int matricula[6];
	float p1;
	float p2;
	float p3;
	float media;
}aluno;

void le(aluno *turma, int qtd){
    int i;
    
    for(i=0; i<qtd; i++) {
        printf("Aluno [%d]:\n", i+1);
        printf(" Digite o nome: ");
        scanf("%s%*c", turma[i].nome);
        printf(" Digite a matricula: ");
        scanf("%d%*c", turma[i].matricula);
        printf(" Digite a nota da P1: ");
        scanf("%f%*c", &turma[i].p1);
        printf(" Digite a nota da P2: ");
        scanf("%f%*c", &turma[i].p2);
        printf(" Digite a nota da P3: ");
        scanf("%f%*c", &turma[i].p3);
        turma[i].media = (turma[i].p1 + turma[i].p2 + turma[i].p3)/3; 
        printf("\n");
    }    
}

void imprime(aluno *turma, int qtd){
    int i;
    for(i=0; i<qtd; i++) {
        printf("\nAluno [%d]:\n", i+1);
        printf(" Nome: ");
        printf(" %s /", turma[i].nome);
        printf(" Matricula: ");
        printf(" %d /", *turma[i].matricula);
        printf(" Nota da P1: ");
        printf(" %.2f /", turma[i].p1);
        printf(" Nota da P2: ");
        printf(" %.2f /", turma[i].p2);
        printf(" Nota da P3: ");
        printf(" %.2f /", turma[i].p3);
        printf(" Media das notas: ");
        printf(" %.2f", turma[i].media);
    }
    printf("\n");
    
}

void ordena_medias(aluno *turma, int qtd){
    int i, j;
    
    aluno reserva_turma[qtd];
    
    for (i = 0; i < qtd; i++){
        for (j = i + 1; j < qtd; j++){
            if (turma[i].media < turma[j].media){
                reserva_turma[0] =  turma[i];
                turma[i] = turma[j];
                turma[j] = reserva_turma[0];
            }
        }
    }    
}

int main (void) {
    aluno turma[MAX];
    
    int qtd;
    printf("Digite o numero de alunos da turma: ");
    scanf("%d", &qtd);
    
    le(turma, qtd);
    
    puts (" Imprimindo dados lidos da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
    
    imprime (turma, qtd);
    
    ordena_medias (turma, qtd);
    
    puts ("\n Imprimindo dados ordenados da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
    
    imprime (turma, qtd);
}
