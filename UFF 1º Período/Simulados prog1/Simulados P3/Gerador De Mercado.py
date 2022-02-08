from random import randint, uniform


def mostrar(arq):
    for lin in arq:
        print(lin, end='')
    return None


nome = input('Insira o nome do arquivo a ser criado/modificado:\n')
arquivo = open(nome, 'w', encoding='utf-8')
tamanhoCodigo = randint(3, 8)
qtdProdutos = int(input('Insira a quantidade de produtos que terá no mercado:\n'))
for produto in range(qtdProdutos):
    for contador in range(tamanhoCodigo):
        # caixa = randint(0, 1)
        caixa = 0
        if bool(caixa):
            arquivo.write(chr(randint(65, 90)))
        else:
            arquivo.write(chr(randint(97, 122)))
    arquivo.write(f'#Produto {produto+1}#{str(randint(0, 1000))}#{str(round(uniform(0.20, 1000), 2))}\n')
arquivo = open(nome, 'r', encoding='utf-8')
print('Pronto! O conteúdo do arquivo ficou assim:\n')
print('============================================')
mostrar(arquivo)
print('============================================')
