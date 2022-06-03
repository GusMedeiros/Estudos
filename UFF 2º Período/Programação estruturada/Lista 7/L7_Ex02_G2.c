#include <stdio.h>
#include <string.h>
int main (void) {
char *frase = "Otimo teste"; // declara-se um ponteiro que aponta para a string "Ótimo teste"
char *p , misterio[80]; // declara-se um ponteiro e um vetor mistério de chars não inicializados
int i = 0;
int j = 0;
p = frase + strlen ( frase ) - 1; // strlen de frase será 11, com -1 será 10. Portanto, p apontará para o 11º char da string.
while (*p != ' ')
{
misterio[i] = *p; 
i ++; p --;
}
/* esse while começa com p apontando ao último elemento. Como o endereço contido em p está decrescendo em 1 a cada iteração,
será guardado o caractere anterior no índice atual (crescente) de misterio. Como o while para ao encontrar espaços, então ele preencherá
o vetor misterio com a palavra teste ao contrário, que é "etset".*/

misterio[i] = ' '; i ++; // fazemos o caractere seguinte ao último do while anterior ser espaço, portanto "etset" vira "etset ".
/* o while seguinte iterará do índice 0 de frase até encontrar um espaço. Portanto, frase[j] será, ao longo da execução, os caracteres de "Otimo".
Cada um desses caracteres será atribuído aos caracteres seguintes a "etset ". Portanto, no final teremos "etset Otimo".*/
while ( frase[j] != ' ')
 {
misterio [i] = frase[j];
j ++; i ++;
}
misterio[i] = '\0'; // como misterio não tinha um caractere \0 ao seu fim, adicionamos aqui, para que possa ser printado.
puts (misterio); // pela documentação, essa função printará o vetor de caracteres mistério sem o caractere \0 e seguintes, colocando um \n ao fim.
// como misterio é "etset Otimo\0" nesse ponto do texto, será printado "etset Otimo\n".
return 0;
}