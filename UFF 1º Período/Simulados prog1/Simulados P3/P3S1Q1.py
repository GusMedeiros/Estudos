def mostrar(dic):
    for k, v in dic.items():
        print(f'Chave: {k}')
        if len(dic[k]) == 1:
            print('Linha em que ela ocorre:')
        else:
            print('Linhas em que ela ocorre:')
        for cont in sorted(v):
            print(f'\t\t{cont}')
    return None


nome = input()
minimo, maximo = map(int, input().split())
arquivo = open(nome, 'r', encoding='utf-8')
dicionario = dict()
contador = 0
for lin in arquivo:
    contador += 1
    lin = lin.rstrip().split()
    for palavra in lin:
        if minimo <= len(palavra) <= maximo and palavra not in dicionario:
            dicionario[palavra] = {contador}
        elif palavra in dicionario:
            dicionario[palavra].add(contador)
arquivo.close()
dicionario = {k: v for k, v in sorted(dicionario.items())}
mostrar(dicionario)
