#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main() {
    setlocale(LC_ALL,"Portuguese");
    printf ("C é\n\"SUPER\"\nFácil!\n");
    system("pause");

    return 0;
}