/* Função principal */
int main(void)
{
    float t1;
    float t2;
    // como testar a função: t1 = converte(30.0);
    printf("Digite a temperatura em Celsius: ");
    /* captura o valor via teclado */
    scanf("%f", &t1);
    /* converte o valor, chamando a função auxiliar */
    t2 = converte(t1);
    /*exibe resultado */
    printf("Temperatura em Fahrenheit: %F\n", t2);
    // ou
    //printf("Resultado=%f", converte(t1));
    return 0;
}
