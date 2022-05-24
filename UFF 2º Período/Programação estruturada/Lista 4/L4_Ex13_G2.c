#include <stdio.h>
#include <string.h>

#define gets(a) fgets(a,sizeof(a),stdin);  a[strcspn(a, "\n")] = '\0';

int main(void) {
  char frase[50];
  int cont;
  printf("Digite uma frase de no maximo 50 caracteres:\n");
  gets(frase);

  for(int i=0;i<strlen(frase);i++)
  {
     if(frase[i]!=32){
       cont=1;
       for(int j=i+1;j<strlen(frase);j++)
      {
        if(frase[i]==frase[j]){
          cont++;
          frase[j]=32;
        }
      }
       printf("%c= %d\n",frase[i],cont);
     }
  }
  return 0;
}
