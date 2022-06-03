#include <string.h>
#include <stdio.h>
void tiraespacos(char* string) {
    char novastring[81];
    int j = 0;
    int i = 0;
    for (; string[j] != '\0'; j++){
        if (string[j] != ' '){
            novastring[i++] = string[j];
        }
    }
    novastring[i] = '\0';
    strcpy(string, novastring);
}
void main() {
    char string[81], novastring[81];
    gets(string);
    tiraespacos(string);
    for(int i = 0; string[i] != '\0';){
        for (int cont=1; cont <= 5; cont++){
            if (string[i] >= 'a' && string[i] <= 'z'){
                string[i] = 'a' + (string[i] + cont) % 'a';
                }
            else if (string[i] >= 'A' && string[i] <= 'Z'){
                string[i] = 'A' + (string[i] + cont) % 'A';
            }
            i++;
        }
    }
    printf("%s", string);
}