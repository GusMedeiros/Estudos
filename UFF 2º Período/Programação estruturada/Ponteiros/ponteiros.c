#include <stdio.h>
#include <locale.h>

void main() 
{
    setlocale(LC_ALL, "Portuguese");
    int numero = 300;
    int *p;
    printf("%d\n", numero);
    p = &numero;
    *p = 10;
    printf("Valor apontado = %d\nEndere�o do valor apontado = %x\nEndere�o do ponteiro = %x", *p, p, &p);
}
