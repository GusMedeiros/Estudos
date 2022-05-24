/* 
3. Construa uma função que receba como argumento de entrada uma cadeia de 20 caracteres e um
caractere e retorne o número de vezes que este caractere aparece na cadeia. 
*/
int contacaracter(char string[], char caractere)
{
    int contador = 0;
    for (int i=0; string[i]!='\0'; i++){
        if (string[i] == caractere)
            contador++;
    }
    return contador;
}