#include <stdio.h>

void main()
{
      int num = 1000;
      while(num <= 9999)
      {
                if(num == (((num/100) + (num % 100)) * ((num/100) + (num%100))))
                       printf("%d: %d+%d=%d -> %d^2 = %d \n",num,num/100,num%100,(num/100)+(num%100),(num/100)+(num%100),num);
                num=num+1;
      }
      getchar();
}
