#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[21], letra;

    printf("Digite a string:");
    scanf("%s",&string);

    printf("Digite a letra:");
    scanf(" %c",&letra);

    for (int i=0; i<20; i++){
        if (letra==string[i]){
            for (int j=i; j<20; j++){
                string[j]=string[j+1];
            }
        }
    }

    printf("%s", string);

    return 0;
}
