#include <stdio.h>

 int main(void)
 {
     int seg,min,hor;
     printf("Digite o tempo total em segundos:");
     scanf("%i", &seg);
     hor=seg/3600;
     seg=seg%3600;
     min=seg/60;
     seg=seg%60;
     printf("total:%i:%i:%i/n,hor,min,seg");
     return 0;
 }
