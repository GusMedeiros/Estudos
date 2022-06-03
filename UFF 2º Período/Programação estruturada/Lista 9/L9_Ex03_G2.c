#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *estado[27] = {"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA","PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado){
    Assalariados *pessoa = (Assalariados*) malloc(sizeof(Assalariados));
    strcpy(pessoa->nome,nome);
    pessoa->sexo=sexo;
    pessoa->idade=idade;
    pessoa->salario=salario;
    strcpy(pessoa->estado,estado);

    return pessoa;
}

void relatorio(Assalariados **ptr, int numAssalariados){
    int i, j, qnt;

    for (j=0; j<27; j++){
        qnt=0;
        for (i=0; i<numAssalariados; i++){
            if (strcmp(ptr[i]->estado,estado[j])==0){
                if ((ptr[i]->sexo=='M')&&(ptr[i]->salario>1000)){
                    qnt++;
                }
            }
        }
        if (qnt>0){
            printf("\nEstado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00",estado[j],qnt);
        }
    }
}

void imprime(Assalariados **ptr, int numAssalariados){
    for (int i=0; i<numAssalariados; i++){
        printf("\nNome: %s", ptr[i]->nome);
        printf("\nSexo: %c", ptr[i]->sexo);
        printf("\nIdade: %d", ptr[i]->idade);
        printf("\nSalario: %.2f", ptr[i]->salario);
        printf("\nEstado: %s \n\n", ptr[i]->estado);
    }
}


int main(void) {

    Assalariados **pessoas;
    int numAssalariados=3;

    pessoas = (Assalariados**)malloc(numAssalariados*sizeof(Assalariados*));

    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");

    imprime(pessoas, numAssalariados);

    relatorio(pessoas,numAssalariados);

    return 0;
}
