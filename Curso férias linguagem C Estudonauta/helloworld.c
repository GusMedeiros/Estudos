#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main() {
    setlocale(LC_ALL,"Portuguese");
    printf ("C �\n\"SUPER\"\nF�cil!\n");
    system("pause");

    return 0;
}