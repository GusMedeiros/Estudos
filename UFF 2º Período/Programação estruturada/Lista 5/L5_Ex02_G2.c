// 2. Mostre e explique (comentando as linhas de código) o que será impresso na tela:
#include<stdio.h>
#include<string.h>
void main()
{
char texto[]= "foi muito facil";
int i;
for (i = 0; texto[i]!='\0'; i++)  // for será executado até a string acabar.
{
if (texto[i] == ' ') break;  // se chegar em um espaço, o for acaba.
}
// como a string contém um espaço no caractere de índice 3, i será 3 quando sair do for.
i++; // i vira 4
for ( ; texto[i]!='\0'; i++) // for será executado até string acabar.
{
printf("%c", texto[i]); /* como i não é resetado e ele era 4 ao início do for, 
será printado do caractere de índice 4 até o fim. Isso corresponde a "muito facil". 
*/
}
}