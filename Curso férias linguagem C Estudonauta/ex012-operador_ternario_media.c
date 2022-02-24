# include <stdio.h>
# include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Primeira nota: ");
    float nota1, nota2, media;
    fflush(stdin);
    scanf("%f", &nota1);
    fflush(stdin);
    printf("Segunda nota: ");
    scanf("%f", &nota2);
    fflush(stdin);
    media = (nota1 + nota2) / 2;
    printf("A média do aluno foi %.1f\n", media);
    printf("A situação é %s", media>=6?"APROVADO":"REPROVADO");
}