#include <stdio.h>
int fibonacci(int n);

int main()
{

    int n;
    scanf("%d", &n);
    fibonacci(n);
    
    
    return 0;
}

int fibonacci(int n){
    int i, fibo[n];
    fibo[0] = 1;
    fibo[1] = 1;

    for(i = 2; i < n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    for(i = 0; i < n; i++){
        printf("%d ", fibo[i]);
    }
    
    return 0;
}