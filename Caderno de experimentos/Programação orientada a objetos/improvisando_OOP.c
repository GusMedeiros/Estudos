/* Experimentando com o conteúdo do vídeo do Fábio Akita (https://youtu.be/Gp2m8ZuXoPg), que achei muito interessante, 
para que possa compreender melhor como a orientação a objetos funciona. Peço desculpas desde já pelo excesso de comentários
que esse arquivo terá, porém é justificado, pois ele é uma tentativa de explicar para mim mesmo o funcionamento das coisas,
já que, até o momento, nunca tinha criado um struct nem mexido com ponteiros sem ser um simples ctrl+v.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carro { /* essa será nossa structe. Aqui, nada mais é do que uma struct comum. Porém, agirá como structe ao
    ser instanciada no resto do programa através de ponteiros, sendo, portanto, alocada na heap.*/
    // variáveis de classe
    int qtd_rodas;
    // variaveis de instância
    char marca[10];
    char modelo[15];
    int potencia_cavalos;

    // metodos
    void (*metodo_mostrar)(struct carro *); 
};
void print_carro(struct carro *self) {
    printf("Marca: %s | Modelo: %s | Potencia: %d cavalos| Rodas: %d\n", self->marca, self->modelo, self->potencia_cavalos, self->qtd_rodas);
} /* É interessante que, por a função estar sendo passada como
referência, na struct carro, é possível utilizá-la mesmo sendo declarada depois, já que a associação ocorre por último,
na main, após as subrotinas já terem sido lidas.*/

struct carro* newCarro /* esse será o método construtor de nossa structe. Portanto, precisamos que os valores que ele criar ou
    alterar sejam alterados globalmente, não só no escopo dessa função. Ou seja, precisamos que tudo seja feito na heap.
    Além disso, como todo método construtor, precisamos retornar a instância ao fim. Como a instância deve ser armazenada na
    heap, declaramos que a função retorna o tipo ponteiro da struct carro. */
    (char marca[],
    char modelo[],
    int potencia_cavalos) {
        struct carro* self = malloc(sizeof(struct carro)); /* aqui, malloc aloca os espaços necessários para
        gerar uma estrutura carro na memória heap, na prática, gerando uma instância. No vídeo, Akita faz o casting do 
        malloc para (struct carro*), entretanto, em minhas pesquisas para tirar dúvidas, me deparei com diversos posts
        não recomendando a prática por mascarar possíveis erros que o compilador detectaria. */
        strcpy(self->marca, marca); 
        /* como self.marca é um ponteiro para o valor de marca, normalmente seria necessário
        utilizar um asterisco *, algo como *marca, para indicar ao compilador que ele deve acessar o endereço, não o valor.
        Entretanto, quando se tratam de membros de structs, utiliza-se ->, que é equivalente ao operador ponto (i.e struct.membro)
        de outras linguagens.*/
        strcpy(self->modelo, modelo);
        self->potencia_cavalos = potencia_cavalos;
        self->qtd_rodas = 4; // valor padrão pois estamos simulando variável de classe.
        self->metodo_mostrar = &print_carro; /* aqui se passa o endereço da função, já que queremos usar a referência da
        função na heap, não gerar uma duplicata dela na stack. Funcionaria da mesma maneira, porém ocuparia mais espaço. */
        return self; // retornamos self, imitando python, que faz isso implicitamente.
    };
void main()
{
    struct carro* siena = newCarro("Fiat","Siena",73);
    siena->metodo_mostrar(siena);

}
