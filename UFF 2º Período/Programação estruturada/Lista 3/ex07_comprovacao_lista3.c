#include <stdio.h>

void main() 
{
    int *pti;
    int veti[]={10,7,2,6,3};
    int pti2;
    pti = veti;

    printf("%d\n", pti[1]);
    // printf("Veti = %x |&Veti =  %x | pti = %x | &pti = %x",veti,  &veti, pti, &pti); // experimentos
}