/*
8. Faça um programa que dado 2 palavras, determine:
a. Se as palavras são iguais;
b. Verifique se a segunda palavra é uma sub string da primeira. Ex: casa e casamento.
*/
#include <string.h>
#include <stdio.h>
int string_e_igual(char palavra1[], char palavra2[])
{
    int contaiguais = 0;
    for (int i=0; palavra1[i]!='\0';i++)
    {
        if (palavra1[i] == palavra2[i])
            contaiguais++;
    }
    if (contaiguais == strlen(palavra1))
        return 1;
    else 
        return 0;

}
int string_e_substring(char palavra1[], char palavra2[])
{
    for (int i = 0; palavra1[i] != '\0'; i++)
    { // para cada caractere da palavra 1
        int caracteresEmComum = 0;
        for (int j=0; palavra2[j] != '\0'; j++)
        { // para cada caractere da palavra 2
            if (palavra1[i+j] == palavra2[j])
            {
                caracteresEmComum++;
                if (caracteresEmComum == strlen(palavra2) - 1)
                    
                    return 1;
            }
            else break;
        }
    }
    return 0;
}
int compara_strings(char palavra1[], char palavra2[])
{
    int igual = 0, substring = 0;
    igual = string_e_igual(palavra1, palavra2);
    if (igual)
        return 2;
    substring = string_e_substring(palavra1, palavra2);
    printf("%d - %d\n", igual, substring);
    return igual+substring;
}

int main()
{
    char palavra1[] = "123";
    char palavra2[] = "123";
    int comparacao = ("%d", compara_strings(palavra1, palavra2)); // 0 = nem igual nem substring, 1 = substring, 2 = igual
    printf("%d", comparacao);
    return comparacao;
}