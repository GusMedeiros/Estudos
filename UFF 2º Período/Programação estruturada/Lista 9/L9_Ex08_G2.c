#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

struct data {
    int dd, mm, aa;
};
typedef struct data Data;

struct compromisso {
    char descricao[81];
    Data dta;
};
typedef struct compromisso Compromisso;

Compromisso* criar_compromisso (char *descricao, int d, int m, int a){
    Compromisso *tarefa=(Compromisso*)malloc(sizeof(Compromisso));
    strcpy(tarefa->descricao, descricao);
    tarefa->dta.dd=d;
    tarefa->dta.mm=m;
    tarefa->dta.aa=a;
    return tarefa;
}

// IMPORTANTE!
int comparar_datas(Data data1, Data data2){

    // retorna 0 se as datas sao iguais
    // retorna 1 se a data1 esta na frente
    // retorna -1 se a data2 esta na frente

    int cmp_dia = data1.dd - data2.dd;
    int cmp_mes = data1.mm - data2.mm;
    int cmp_ano = data1.aa - data2.aa;

    if (cmp_ano != 0){
        return cmp_ano / abs(cmp_ano);
    }

    if (cmp_mes != 0){
        return cmp_mes / abs(cmp_mes);
    }

    if (cmp_dia != 0){
        return cmp_dia / abs(cmp_dia);
    }

    return 0;
}

Compromisso* busca (int n, Compromisso** vet, int d, int m, int a) {
    /* no in�cio consideramos todo o vetor */

    Data data_procurada = {.dd=d, .mm = m, .aa = a};

    int ini = 0;
    int fim = n-1;
        while (ini <= fim) {        /* enquanto a parte restante for maior que zero */
            int meio = (ini + fim) / 2;
            // printf("meio: %d\n", meio);

            int cmp_datas = comparar_datas(data_procurada, vet[meio]->dta);

            if (cmp_datas == 0){
                return vet[meio];
            }

            if (cmp_datas > 0){
                ini = meio + 1;
            }

            if (cmp_datas < 0){
                fim = meio - 1;
            }

        }
        return NULL;
}

void inserir_vetor_compromisso(Compromisso** vetor_compromissos, int tam_vet, Compromisso* novo_compromisso){

    Compromisso* compromisso_atual = novo_compromisso;

    for (int i = 0; i < tam_vet; i++){

        if (vetor_compromissos[i] == NULL){
            vetor_compromissos[i] = compromisso_atual;
            break;
        }
        else{
            int cmp_datas = comparar_datas(novo_compromisso->dta, vetor_compromissos[i]->dta);
            if (cmp_datas < 0){
                Compromisso* temp = compromisso_atual;
                compromisso_atual = vetor_compromissos[i];
                vetor_compromissos[i] = temp;
            }
        }
    }
}

void print_compromisso(Compromisso* compromisso){
    printf("descricao: %s\n\n", compromisso->descricao);
    printf("data: %d/%d/%d\n", compromisso->dta.dd, compromisso->dta.mm, compromisso->dta.aa);
}

void print_vetor_compromissos(Compromisso** vetor_compromissos, int tam){
    for (int i = 0; i < tam; i++){
        print_compromisso(vetor_compromissos[i]);
        printf("\n-----------\n");
    }
}

int main(){
    Compromisso* agenda[N];

    for (int i = 0; i < N; i++){
        agenda[i] = NULL;
    }

    int d, m, a;
    int pos = 0;

    for (int i=0; i<N; i++){
        char nome[81];
        printf("\nDigite a descricao do compromisso: ");
        scanf("%s", nome);
        printf("Digite a data: ");
        scanf("%d/%d/%d", &d, &m, &a);
        Compromisso * novo_compromisso = criar_compromisso(nome, d, m, a);
        inserir_vetor_compromisso(agenda, N, novo_compromisso);
    }

    print_vetor_compromissos(agenda, N);

    printf("\nDigite a data a ser procurada (dd/mm/aa): ");
    scanf("%d/%d/%d", &d, &m, &a);

    Compromisso* compromisso_buscado = busca(N, agenda, d, m, a);

    if (compromisso_buscado != NULL){
        printf("Compromisso: %s", compromisso_buscado->descricao);
    }else{
        printf("nao achou compromisso\n");
    }

    return 0;
}

