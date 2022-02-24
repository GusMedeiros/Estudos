#include <stdio.h>
#include <locale.h>
void main(){
    setlocale(LC_ALL, "Portuguese");
    printf("%s tem %d anos de idade.\n", "Gustavo", 21);
    printf("Seu peso atual é de: %7.2fKg", 97.0);
}
