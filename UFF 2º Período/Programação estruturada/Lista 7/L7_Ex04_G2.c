#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void vetor(){
    int i;
    char v[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
    for (i=0;i<26;i++){
        printf("%c \n", v[i]);
    }
}

int main(){
    vetor();
}
