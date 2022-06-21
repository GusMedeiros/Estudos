#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
char nome [81];
float nota1 , nota2;
} ALUNO;
ALUNO* load_alunos(char* nome_arquivo, int qtd){
    FILE *f = fopen(nome_arquivo, "rb");
    ALUNO* vetor = (ALUNO*) malloc(sizeof(ALUNO) * qtd);
    fread(vetor, sizeof(ALUNO), qtd, f);
    fclose(f);
    return vetor;
}
ALUNO* save_alunos(ALUNO* vetor, char* nome_arquivo, int qtd){
    FILE* f = fopen(nome_arquivo, "wb");
    fwrite(vetor, sizeof(ALUNO), qtd, f);
    fclose(f);
}

ALUNO** filtrar_aprovados(ALUNO* vetor, int tamanho){
    int tamanhonovo = 0;
    for(int i = 0; i<tamanho; i++){
        if ((vetor[i].nota1 + vetor[i].nota2)/2 >= 6){
            tamanhonovo++;  
        }
    }
    ALUNO** vetornovo = (ALUNO**) malloc(sizeof(ALUNO*) * tamanhonovo);
    for(int i=0, inovo = 0; i<tamanho; i++) {
        if ((vetor[i].nota1 + vetor[i].nota2)/2 >= 6){
            vetornovo[inovo] = &vetor[i];
            inovo++;  
        }
    }
    return vetornovo;
}
void consultar_aluno(ALUNO* vetor, char nome[81], int tamanho) {
    for(int i=0; i<tamanho; i++){
        if (vetor[i].nome == nome){
            printf("Nome do aluno: %s", vetor[i].nome);
            printf("Nota 1 do aluno: %.2f", vetor[i].nota1);
            printf("Nota 2 do aluno: %.2f", vetor[i].nota2);
            return;
        }
    }

} 
void alterar_aluno(ALUNO* vetor, char nome[81], int tamanho){
    for(int i=0; i<tamanho; i++){
        if (vetor[i].nome == nome){
            printf("Nome atual: %s\n", vetor[i].nome);
            printf("Insira o novo nome: \n");
            fflush(stdin);
            gets(vetor[i].nome);
            printf("Nota1 atual: %.2f", vetor[i].nota1);
            printf("Insira a nova nota 1: \n");
            scanf("%.2f", &vetor[i].nota1);
            fflush(stdin);
            printf("Nota2 atual: %.2f\n", vetor[i].nota2);
            printf("Insira a nova nota 21: \n");
            fflush(stdin);
            scanf("%.2f", &vetor[i].nota2);
            return;
        }
    }
}
ALUNO* excluir_aluno(ALUNO* vetor, char nome[81], int total_alunos)
{
    int novo_total = total_alunos-1;
    ALUNO* novo_vetor = (ALUNO*) malloc(sizeof(ALUNO) * novo_total);
    for(int i=0, i_novo = 0; i<total_alunos; i++, i_novo++){
        if (strcmp(vetor[i].nome, nome)) // se não for o aluno a ser deletado simplesmente copia
        { 
            novo_vetor[i_novo] = vetor[i];
        }
        else {
            i_novo--; // se for o aluno a ser deletado, ignoramos e voltamos um índice para compensar o acréscimo que virá
        }
    } 
    printf("Se o aluno existia, foi excluído com sucesso.\n");
    return novo_vetor;
}

ALUNO* incluir_aluno(ALUNO* vetor_original, int tamanho, char nome[81], float nota1, float nota2){
    ALUNO* novo_vetor = (ALUNO*) malloc(sizeof(ALUNO) * (tamanho+1));
    for (int i=0; i<tamanho; i++){
        novo_vetor[i] = vetor_original[i];
    }
    strcpy(novo_vetor[tamanho+1].nome,nome);
    novo_vetor[tamanho+1].nota1 = nota1;
    novo_vetor[tamanho+1].nota2 = nota2;
}
void main() {
    int tamanho = 4;
    FILE *f = fopen("alunos.bin", "wb");
    for(int i=0; i < 4; i++)
    {
        ALUNO aluno_atual = {"nome", 4, 4};
        fwrite(&aluno_atual, sizeof(ALUNO), 1, f);
    }
    fclose(f);
    ALUNO* vetor = load_alunos("alunos.bin", tamanho);
    ALUNO** aprovados = filtrar_aprovados(vetor, tamanho);
    while(1){
        int escolha = 0;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Escolha uma acao:\n");
        printf("1 - incluir aluno novo\n");
        printf("2 - alterar aluno existente\n");
        printf("3 - consultar aluno existente\n");
        printf("4 - excluir um aluno\n");
        printf("5 - sair e salvar alteracoes\n");
        printf("Insira sua escolha: ");
        fflush(stdin);
        scanf("%d", &escolha);
        switch (escolha)
        {
            char nome[81] = "\0";
            case 1:
                printf("Insira o nome do aluno a ser inserido: ");
                gets(nome);
                float nota1, nota2;
                printf("Insira a nota 1 do aluno: ");
                scanf("%f", &nota1);
                printf("Insira a nota 2 do aluno: ");
                scanf("%f", &nota2);
                vetor = incluir_aluno(vetor, tamanho, nome, nota1, nota2);
                tamanho++;
            case 2:
                alterar_aluno(vetor, nome, tamanho);
                break;
            case 3:
                consultar_aluno(vetor, nome, tamanho);
                break;
            case 4:
                printf("Insira o nome do aluno a ser excluido: ");
                fflush(stdin);
                gets(nome);
                tamanho = excluir_aluno(vetor, nome, tamanho);
                break;
        }
    }
    
}
