# include <stdio.h>

typedef struct _ALUNO {
    char nome [81];
} ALUNO;

typedef struct _node {
    ALUNO* aluno;
    NODE* next; 
} NODE;

NODE* incluir_inicio(NODE* inicio, ALUNO* novo){
    NODE* novo_inicio = (NODE*) malloc(sizeof(NODE));
    novo_inicio->aluno = novo;
    novo_inicio->next = inicio;
    return novo_inicio;
}
void imprimir_lista(NODE* inicio){
    NODE* node_atual = inicio;
    while (node_atual != NULL) {
        printf("%s", node_atual->aluno->nome);
        node_atual = node_atual->next;
    }
}

void excluir_aluno(ALUNO* aluno_alvo, NODE* inicio_lista){
    NODE* node_atual = inicio_lista;
    while(node_atual->next->aluno != aluno_alvo && node_atual != NULL) {
        node_atual = node_atual->next;
    }
    if (node_atual == NULL) return;
    NODE* node_alvo = node_atual->next;
    node_atual->next = node_alvo->next;
    free(node_alvo);
}

void alterar_aluno(ALUNO* aluno_troca, NODE* inicio_lista, ALUNO* aluno_novo) {
    NODE* node_atual = inicio_lista;
    while(node_atual->aluno != aluno_troca && node_atual != NULL) {
        node_atual = node_atual->next;
    }
    node_atual->aluno = aluno_novo;

}