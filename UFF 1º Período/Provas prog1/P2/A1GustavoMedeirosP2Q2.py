from os import remove, rename


def checarcodigo(prod, arq):
    prod = prod.split('#')
    for lin in arq:
        if lin.split('#')[0] == prod[0]:
            return False
    return True


def inserir_copia(prod, arq, nm):
    jainserido = False
    novoarq = open(nm+'Temp', 'w')
    contador = 0
    for lin in arq:
        contador += 1
        if prod.split('#')[0] < lin.split('#')[0] and not jainserido:
            novoarq.write(prod + '\n')
            jainserido = True
        if prod.split('#')[0] == lin.split('#')[0]:
            return False
        novoarq.write(lin)
    arq.close()
    novoarq.close()
    return True


def mostrar(arq):
    for lin in arq:
        print(lin, end='')
    return None


nome = input()
novoProduto = input()
arquivo = open(nome, 'r')
repetido = inserir_copia(novoProduto, arquivo, nome)
if repetido:
    print(f'Conteúdo do Supermercado {nome} antes:')
    arquivo = open(nome, 'r')
    mostrar(arquivo)
    arquivo.close()
    remove(nome)
    rename(nome+'Temp', nome)
    print(f'\nConteúdo do Supermercado {nome} depois:')
    arquivo = open(nome, 'r')
    mostrar(arquivo)
    arquivo.close()
else:
    print('Código já existe!!!')
    remove(nome+'Temp')
