#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Me diga tr�s n�meros e eu colocarei\n");
    printf("eles em ordem pra voc�.\n\n");
    printf("Primeiro n�mero: ");
    int n1, n2, n3, primeiro, maior, menor, intermediario;
    fflush(stdin);
    scanf("%d", &n1);
    printf("Segundo n�mero: ");
    fflush(stdin);
    scanf("%d", &n2);
    printf("Terceiro n�mero: ");
    fflush(stdin);
    scanf("%d", &n3);
    if (n1 >= n2) {
        maior = n1;
        menor = n2;
    }
    else {
        maior = n2;
        menor = n1;
    }
    if (maior < n3) {
        maior = n3;
    }
    if (menor > n3) {
        menor = n3;
    }
    if (n1 != maior && n1 != menor) {
        intermediario = n1;
    }
    else if (n2 != maior && n2 != menor) {
        intermediario = n2;
    }
    else {
        intermediario = n3;
    }
    printf("%d %d %d", menor, intermediario, maior);
}