#include <stdio.h>

int main(void) {
  int vet[6]={1,2,3,4,5,6};
  int *init, *end;

  init=vet;
  end=vet+5;

  for(int i=1;i<=3;i++){
    printf("Pontero do inicio: %d\nPonteiro do final %d\n\n",*init,*end);
    init++;
    end--;
  }
  return 0;
}
