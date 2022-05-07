#include <stdio.h>
void main()
{
    int a = 1, b = 140;
    char c[] = "teste";
    printf("%d", *(&a+1));
}