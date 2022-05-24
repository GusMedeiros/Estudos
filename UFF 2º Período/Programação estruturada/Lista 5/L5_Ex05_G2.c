#include <stdio.h>
#include <string.h>
void main()
{
char frase[80]="o rato roeu a roupa do rei de roma";
char *p;
p = frase;
p[2]='m';
p[6]='\0';
printf("%s\n", frase);
p = p + 3;
printf("%s\n",p);
printf("%d\n",strlen(frase));
}
/* "o rato roeu a roupa do rei de roma" - string original
com p[2] = 'm', a terceira letra ('r') vira m.
com p[6] = '\0', faz com que a sétima letra(' ') em diante fique inacessível para leitores de string
primeiro print:
-> o mato

com p = p+3, o ponteiro será lido a partir da terceira letra ('m')
-> ato

os caracteres da string frase serão contados até encontrar um '\0'. Como nosso sétimo caractere é '\0',
serão contados 6 caracteres.
-> 6
*/