#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    int a = 4, b = 7, c = 2;
    printf("a>b or a>c = %s\n", a>b || a>c?"true":"false");
    a = 7, b = 1;
    printf("%d", a ^ b);
}