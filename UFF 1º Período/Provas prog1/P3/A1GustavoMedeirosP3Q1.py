# Q1	Faça um programa em Python contendo subprogramas, que leia da primeira linha da entrada padrão o nome de um arquivo
# texto, contendo em cada linha o cpf de um apostador e seis números apostados por ele, separados por #, ou  seja:
# cpf#num1#num2#num3#num4#num5#num6
#
# Na segunda linha da entrada padrão leia os números sorteados, separados por espaços em branco.
#
# Leia o arquivo e produza um dicionário (dict()) , onde a chave é a quantidade de acertos (6,5,4 e 3) e o valor é um
# set de cpfs que acertaram. Portanto, aquelas apostas que tiveram 2, 1 ou 0 acertos não entram no dicionário.
#
# Ao final, mostre o conteúdo do dicionário produzido, ordenado decrescentemente pela quantidade de acertos (6,5,4 e 3).
#  Sendo que para cada quantidade de acertos mostre um cpf por linha.


def gerardict(nm, numsort):
    dic = dict()
    arq = open(nm, 'r')
    for lin in arq:
        lin = lin.rstrip().split('#')  # pega a linha, tira o \n e separa os itens
        acrts = len(numsort.intersection(lin))
        if acrts >= 3:  # só entra no dicionário se for mais de 3 acertos
            cpf = lin[0]
            if acrts in dic.keys():
                dic[acrts].add(cpf)
            else:
                dic[acrts] = {cpf}
    arq.close()
    return dic


def mostrardicionario(dic):
    for k in range(6, 2, -1): # conforme a questão pede, será exibido em ordem decrescente de acertos.
        if k in dic.keys():
            print(f'=-=-=-=-= {k} Acertos: =-=-=-=-=')
            for v in dic[k]:  # como as chaves são inteiros, podemos iterar sobre os cpfs do set de dic[k]
                print(v)
    return None


# main
nome = input()
NumerosSorteados = {k for k in input().split()}
dicionario = gerardict(nome, NumerosSorteados)
mostrardicionario(dicionario)
