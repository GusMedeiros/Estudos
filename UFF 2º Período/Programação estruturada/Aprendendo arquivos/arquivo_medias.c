#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main() {
    setlocale(LC_ALL,"Portuguese");
    int qtdalunos;
    FILE* Arquivo = fopen("notas.txt", "r");
    if (Arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fscanf(Arquivo, "%d", &qtdalunos);
    for(int i = 0; i < qtdalunos; i++){
        float nota1 = 0, nota2 = 0, nota3 = 0;
        fscanf(Arquivo, "%f %f %f", &nota1, &nota2, &nota3);
        printf("Média %d = %.2f\n", i+1, (nota1 + nota2 + nota3) / 3);
    }
    fclose(Arquivo);
}