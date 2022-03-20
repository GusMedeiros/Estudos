/* Experimentando com o conte�do do v�deo do F�bio Akita (https://youtu.be/Gp2m8ZuXoPg), que achei muito interessante, 
para que possa compreender melhor como a orienta��o a objetos funciona. Pe�o desculpas desde j� pelo excesso de coment�rios
que esse arquivo ter�, por�m � justificado, pois ele � uma tentativa de explicar para mim mesmo o funcionamento das coisas,
j� que, at� o momento, nunca tinha criado um struct nem mexido com ponteiros sem ser um simples ctrl+v.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carro { /* essa ser� nossa structe. Aqui, nada mais � do que uma struct comum. Por�m, agir� como structe ao
    ser instanciada no resto do programa atrav�s de ponteiros, sendo, portanto, alocada na heap.*/
    // vari�veis de classe
    int qtd_rodas;
    // variaveis de inst�ncia
    char marca[10];
    char modelo[15];
    int potencia_cavalos;

    // metodos
    void (*metodo_mostrar)(struct carro *); 
};
void print_carro(struct carro *self) {
    printf("Marca: %s | Modelo: %s | Potencia: %d cavalos| Rodas: %d\n", self->marca, self->modelo, self->potencia_cavalos, self->qtd_rodas);
} /* � interessante que, por a fun��o estar sendo passada como
refer�ncia, na struct carro, � poss�vel utiliz�-la mesmo sendo declarada depois, j� que a associa��o ocorre por �ltimo,
na main, ap�s as subrotinas j� terem sido lidas.*/

struct carro* newCarro /* esse ser� o m�todo construtor de nossa structe. Portanto, precisamos que os valores que ele criar ou
    alterar sejam alterados globalmente, n�o s� no escopo dessa fun��o. Ou seja, precisamos que tudo seja feito na heap.
    Al�m disso, como todo m�todo construtor, precisamos retornar a inst�ncia ao fim. Como a inst�ncia deve ser armazenada na
    heap, declaramos que a fun��o retorna o tipo ponteiro da struct carro. */
    (char marca[],
    char modelo[],
    int potencia_cavalos) {
        struct carro* self = malloc(sizeof(struct carro)); /* aqui, malloc aloca os espa�os necess�rios para
        gerar uma estrutura carro na mem�ria heap, na pr�tica, gerando uma inst�ncia. No v�deo, Akita faz o casting do 
        malloc para (struct carro*), entretanto, em minhas pesquisas para tirar d�vidas, me deparei com diversos posts
        n�o recomendando a pr�tica por mascarar poss�veis erros que o compilador detectaria. */
        strcpy(self->marca, marca); 
        /* como self.marca � um ponteiro para o valor de marca, normalmente seria necess�rio
        utilizar um asterisco *, algo como *marca, para indicar ao compilador que ele deve acessar o endere�o, n�o o valor.
        Entretanto, quando se tratam de membros de structs, utiliza-se ->, que � equivalente ao operador ponto (i.e struct.membro)
        de outras linguagens.*/
        strcpy(self->modelo, modelo);
        self->potencia_cavalos = potencia_cavalos;
        self->qtd_rodas = 4; // valor padr�o pois estamos simulando vari�vel de classe.
        self->metodo_mostrar = &print_carro; /* aqui se passa o endere�o da fun��o, j� que queremos usar a refer�ncia da
        fun��o na heap, n�o gerar uma duplicata dela na stack. Funcionaria da mesma maneira, por�m ocuparia mais espa�o. */
        return self; // retornamos self, imitando python, que faz isso implicitamente.
    };
void main()
{
    struct carro* siena = newCarro("Fiat","Siena",73);
    siena->metodo_mostrar(siena);

}
