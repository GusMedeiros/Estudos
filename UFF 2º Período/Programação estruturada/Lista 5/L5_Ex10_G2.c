/*
10. Fazer um programa para cadastro e diálogo de login. O programa deve:
    a. Cadastrar um nome de usuário via teclado. O nome de usuário tem, no máximo, 8 caracteres,
    sendo válidos somente os caracteres numéricos e as letras maiúsculas ou minúsculas. Somente os
    caracteres válidos devem ser exibidos no console durante a digitação do nome de usuário.
    
    b. Cadastrar uma senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
    com a diferença de que são exibidos somente asteriscos no console à medida que a senha é digitada.
    
    c. Receber um novo nome de usuário e uma nova senha, utilizando os mesmos procedimentos
    descritos nos itens a e b.
    
    d. Comparar o nome de usuário cadastrado com o recebido posteriormente e a senha cadastrada
    com a senha recebida. Caso sejam idênticos, informar “OK”, do contrário, informar “Acesso
    negado”. 
*/
# include <stdio.h>
# include <conio.h>
# include <string.h>
char* getform(char* campo, int tamanho, int secreto)
{
    char caractere;
    for (int i = 0; i < tamanho-1;)
    {
        caractere = getch();
        if (caractere >= 'a' && caractere <= 'z' || caractere >= 'A' && caractere <= 'Z'
            || caractere >= '0' && caractere <= '9') {
            campo[i] = caractere;
            if (!secreto)
            {
                
                printf("%c", caractere);
            }
            else 
            {
                printf("*");
            }
            i++;
        }
    campo[tamanho-1] = '\0';
    } 
    printf("\n");
}

void main()
{
    char usuario[9], senha[9], usuario2[9], senha2[9];

    printf("Cadastre seu nome de usuario:\n");
    getform(usuario, 9, 0);
    printf("Cadastre sua senha:\n");
    getform(senha, 9, 1);
    printf("Logue com seu nome de usuario:\n");
    getform(usuario2, 9, 0);
    printf("Logue com sua senha:\n");
    getform(senha2, 9, 1);
    if (!strcmp(usuario, usuario2) && !strcmp(senha, senha2)){
        printf("OK\n");
    }
    else
    {
        printf("Acesso negado");
    }
}