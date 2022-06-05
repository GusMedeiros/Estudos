#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct data {
int dia, mes, ano;
} Data;


typedef struct local {
char ender[81]; /* endereço do local de provas */
int sala; /* numero sala */
} Local;

typedef struct notas {
float geral; /* prova de conhecimentos gerais */
float especifica; /* prova de conhecimentos
especificos */
} Notas;

typedef struct candidato {
int inscr; /* numero de inscricao */
char nome[81]; /* nome do candidato */
Data nasc; /* data de nascimento */
Local *loc; /* local de prova */
Notas nt; /* notas de prova */
} Candidato;

int main(){
	int escolha;
	printf("1-adicionar novos alunos\n2-imprimir alunos cadastrados\n3-mudar o endereco de um aluno\n");
	scanf("%d", &escolha);
	int max,i;
	Local *loc;
	Candidato *vetorcandidatos;
	while(escolha!=0){
		if(escolha==1){
			printf("Quantos candidatos?");
			scanf("%d", &max);
			loc=(Local*)malloc(sizeof(Local)*max);
			vetorcandidatos = (Candidato*)malloc (max*sizeof(Candidato));
			if (vetorcandidatos==NULL) exit(1);
			for (i=0;i<max;i++){
				printf("Digite a inscricao do aluno:\n");
				scanf("%d", &vetorcandidatos[i].inscr);
				printf("Digite o nome do aluno:\n");
				scanf(" %80[^\n]", vetorcandidatos[i].nome);
				printf("Digite a data de nascimento do aluno:\n");
				scanf("%d/%d/%d", &vetorcandidatos[i].nasc.dia, &vetorcandidatos[i].nasc.mes, &vetorcandidatos[i].nasc.ano);
				printf("Digite o endereco de prova:\n");
				vetorcandidatos[i].loc = &loc[i];
				scanf(" %80[^\n]", vetorcandidatos[i].loc->ender);
				printf("Digite a sala:\n");
				scanf("%d", &vetorcandidatos[i].loc->sala);
				printf("Digite a nota geral do aluno:\n");
				scanf("%f", &vetorcandidatos[i].nt.geral);
				printf("Digite a nota especifica do aluno:\n");
				scanf("%f", &vetorcandidatos[i].nt.especifica);
				printf("1-adicionar novos alunos\n2-imprimir alunos cadastrados\n3-mudar o endereco de um aluno\n");
				scanf("%d", &escolha);
			}
		}
		
		if(escolha==2){
			for (i=0;i<max;i++){
				printf("%d\n", vetorcandidatos[i].inscr);
				printf("%s\n", vetorcandidatos[i].nome);
				printf("%d/%d/%d\n", vetorcandidatos[i].nasc.dia, vetorcandidatos[i].nasc.mes, vetorcandidatos[i].nasc.ano);
				printf("%s\n", vetorcandidatos[i].loc->ender);
				printf("%d\n", vetorcandidatos[i].loc->sala);
				printf("%.2f\n", vetorcandidatos[i].nt.geral);
				printf("%.2f\n", vetorcandidatos[i].nt.especifica);
				printf("1-adicionar novos alunos\n2-imprimir alunos cadastrados\n3-mudar o endereco de um aluno\n");
				scanf("%d", &escolha);
			}			
		}
		
		if(escolha==3){
			int inscricaob;
			printf("Digite o aluno\n");
			scanf("%d", &inscricaob);
			printf("Digite o novo endereco de prova:\n");
			scanf(" %80[^\n]", &vetorcandidatos[inscricaob].loc->ender);
			printf("Digite a nova sala:\n");
			scanf("%d", &vetorcandidatos[inscricaob].loc->sala);
			printf("1-adicionar novos alunos\n2-imprimir alunos cadastrados\n3-mudar o endereco de um aluno\n");
			scanf("%d", &escolha);
		}
	}
			
	return 0;
}