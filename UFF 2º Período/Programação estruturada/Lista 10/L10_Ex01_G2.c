typedef struct funcionario {
char nome[81]; /* nome do funcionário */
float valor_hora; /* valor da hora de trabalho em Reais */
int horas_mes; /* horas trabalhadas em um mês */
} Funcionario;

#include <stdio.h>
#include <stdlib.h>

void carrega (int n, Funcionario** vet, char* arquivo);

void main() {
    char nome[81];
    int tamanho;
    char arquivo[] = "funcionarios.txt";
    FILE *f = fopen(arquivo, "r");
    for (tamanho = 0;(fgets(nome, 81, f) != NULL); tamanho++);
    tamanho /= 2;
    fclose(f);
    Funcionario **vetor = (Funcionario**) malloc(sizeof(Funcionario*) * tamanho);
    carrega(tamanho, vetor, arquivo);
    for (int i=0; i<tamanho; i++){
        printf("%s\n%.1f %d\n", vetor[i]->nome, vetor[i]->valor_hora, vetor[i]->horas_mes);
    }
    
}

void carrega (int n, Funcionario** vet, char* arquivo){
    FILE* f = fopen(arquivo, "r");
    for (int i=0; i<n; i++)
    {
    Funcionario* funcionario_atual = (Funcionario*) malloc(sizeof(Funcionario));
    fgets(funcionario_atual->nome, 81, f);
    fscanf(f, "%f %d\n", &funcionario_atual->valor_hora, &funcionario_atual->horas_mes);
    vet[i] = funcionario_atual;
    }
}