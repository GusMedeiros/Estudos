# include <stdio.h>
int conversao_binaria(int n, int *vetor_binario, int tamanho, int tamanho_fixo) // o "tamanho_fixo" � usado somente na �ltima chamada da fun��o no vetor_bin�rio
{
    vetor_binario[tamanho] = (n % 2); // as �ltimas posi��es do vetor receber�o o resto dessa divis�o
    n /= 2; // o "n" precisa ser divido para continuar os pr�ximos c�lculos corretamente
    if(tamanho > 0) // esse "if" � usado em todas as fun��es recursivas exceto a �ltima chamada quando o tamamho for igual a zero
    {
        tamanho--; // a fun��o a ser chamada receber� um tamanho decrementado
        return conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // chama a fun��o recursivamente com tamanho decrementado
    }

    if(tamanho == 0) // apenas na �ltima chamada ser� feito isso
    {
        int indice, binario; // bin�rio ser� para armazenar os valores convertidos em bin�rio e valor de retorno
        binario = 0;
        for(indice = 0; indice < tamanho_fixo; indice++)
        {
            if(indice == 0)
            {
                if(vetor_binario[indice] == 0) // se o vetor tem o valor zero
                {
                    binario = 0;
                }
                else // se o vetor tem o valor 1
                {
                    binario = 1;
                }
            }
            else
            {
                if(vetor_binario[indice] == 0) // se o valor de tal posi��o (indice) do vetor for igual a zero, ent�o acrescenta um zero ao valor de bin�rio
                {
                    binario *= 10;
                }
                else
                {
                    binario = (binario * 10) + 1; // se o valor de tal posi��o (indice) for igual a 1, ent�o acrescenta um "1" ao valor de bin�rio
                }
            }
        }
        return binario;
    }
}

int main(void)
{
    int n; // numero a ser convertido em bin�rio
    printf("Insira um valor inteiro decimal para ser convertido em binario: "); // pergunta ao usu�rio
    scanf("%d", &n); // leitura do numero a ser convertido em bin�rio
    int indice, tamanho, tamanho_fixo, numero_binario;

    tamanho = 0; // zerando o tamanho do vetor
    for(indice = n; indice > 0; )
    {
        indice /= 2; // la�o para especificar o tamanho do vetor
        tamanho++;
    }
    tamanho_fixo = tamanho; // usado na fun��o recursiva
    int vetor_binario[tamanho]; // vetor com o tamanho encontrado anteriormente no la�o
    tamanho -= 1; // decrementa o tamanho para ser usado nessa forma na fun��o
    numero_binario = conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // a fun��o retornar� um inteiro formatado como um "bin�rio"
    printf("\nO numero digitado em binario e': %d", numero_binario);
    getch();
    return 0;
}



//Codigo funcionado como previsto
//teste 1: 12 resultado 1100 correto
//teste 2: 24 resultado 11000 correto
//teste 3: 5 resultado 101 correto
