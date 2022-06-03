#include <stdio.h>

void f1 ( int v) {
v = v + 1; // como v aqui é igual a 1, v = 1+1 = 2
printf (" f1 = %d\n " , v ); // como v aqui é igual a 2, printará f1 = 2
}

void f2 ( int *v) {
*v = *v + 1; // o valor apontado receberá o valor apontado + 1. Portanto, v será 2, mesmo fora da função, pois existe fora do escopo.
printf (" f2 = %d\n " , *v ); // printará f2 = 2.
}

int f3 ( int v) {
v = v + 1;  // como aqui v vale 2, v = 2 + 1 = 3
printf (" f3 = %d\n " , v ); // f3 = será printado 3.
return v; // retornamos 3.
}

int main (void) {
int v = 1;
f1 ( v ); // o parametro v da função será 1
f2 (&v );  // enviaremos v por referência.
v = f3 ( v ); // enviaremos v por valor à função f3. aqui, v vale 2. Em seguida, a função retorna o valor 3. v será 3.
printf (" main = %d \n" , v ); // portanto, printar v é printar 3. será printado main = 3.
return 0;
}