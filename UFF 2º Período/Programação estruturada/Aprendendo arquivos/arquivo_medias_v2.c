#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main() {
    setlocale(LC_ALL,"Portuguese");
    FILE* Arquivo = fopen("notas_sem_qtd.txt", "r");
    FILE* Arquivo_out = fopen("notas_saida.txt", "w");
    if (Arquivo == NULL || Arquivo_out == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    float nota1 = 0, nota2 = 0, nota3 = 0;
    int i = 0;
    while(fscanf(Arquivo, "%f %f %f", &nota1, &nota2, &nota3) == 3) // segundo a documentação, fscanf retorna a quantidade de
    // variáveis atribuídas com sucesso. Portanto, podemos fazer esse while, que garante que chegaremos até o final do arquivo.
    {
        i++;
        fprintf(Arquivo_out, "Média = %.2f\n", (nota1 + nota2 + nota3) / 3);
    }
    fclose(Arquivo);
    fclose(Arquivo_out);
}