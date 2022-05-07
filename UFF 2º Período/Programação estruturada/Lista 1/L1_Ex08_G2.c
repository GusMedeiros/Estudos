#include <stdio.h>
int total_de_notas(int valor);

int main()
{
    int quantia, num_notas;
    
    scanf("%d", &quantia);
    num_notas = total_de_notas(quantia);
    printf("O menor numero de notas para obter o montante fornecido eh de %d nota(s).", num_notas);
    
    return 0;
}

int total_de_notas(int valor){
    int total, n100, n50, n20, n10, n5, n2, n1;
    
    n100 = (valor-valor%100)/100;
    valor = valor - n100*100;
    n50 = (valor-valor%50)/50;
    valor = valor - n50*50;
    n20 = (valor-valor%20)/20;
    valor = valor - n20*20;
    n10 = (valor-valor%10)/10;
    valor = valor - n10*10;
    n5 = (valor-valor%5)/5;
    valor = valor - n5*5;
    n2 = (valor-valor%2)/2;
    valor = valor - n2*2;
    n1 = (valor-valor%1)/1;
    valor = valor - n1*1;
    total = n100 + n50 + n20 + n10 + n5 + n2 + n1;
    
    return total;
}