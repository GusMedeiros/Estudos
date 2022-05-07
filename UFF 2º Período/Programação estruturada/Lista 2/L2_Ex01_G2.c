#include <stdio.h>

int main()
{
    int A;
    
    scanf("%d", &A);
    if (A != 2 & A != 3 & A!= 5 & A !=7){
        if (A == 1 || A%2 == 0 || A%3 == 0 || A%5 == 0 || A%7 == 0){
            printf("NUMERO NAO PRIMO");
        }
        else{
        printf("NUMERO PRIMO");
    }
    }
    else{
        printf("NUMERO PRIMO");
    }
    return 0;
}
