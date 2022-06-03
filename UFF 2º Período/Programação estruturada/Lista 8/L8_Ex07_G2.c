#include <stdio.h>

int main(void) {
  int tabela[5][5]={
    {00,15,30,05,12},
    {15,00,10,17,28},
    {30,10,00,03,11},
    {05,17,03,00,80},
    {12,28,11,80,00}
  };

  int x,y;
  printf("Selecione as cidades entre 1 e 5, caso digite 0 na primeira e na segunda cidade o programa sera encerrado\n\n");
  do{
    do{
      printf("Digite a primeira cidade: ");
      scanf("%d",&x);
      if(x<0 || x>5)
        printf("Cidade invalida, tente novamente\n\n");
    }while(x<0 || x>5);

    do{
      printf("Digite a segunda cidade: ");
      scanf("%d",&y);
      if(y<0 || y>5)
        printf("Cidade invalida, tente novamente\n\n");
    }while(y<0 || y>5);

    if(x!=0 && y!=0)
      printf("A distancia entre a cidade %d e a cidade %d � de: %d\n\n",x,y,tabela[x-1][y-1]);
  }while(x!=0 || y!=0);
  return 0;
}
