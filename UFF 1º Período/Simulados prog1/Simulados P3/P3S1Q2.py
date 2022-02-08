nome = input()
minimo, maximo = map(float, input().split())
arquivo = open(nome, 'r', encoding='utf-8')
dicionario = dict()
for prod in arquivo:
    prod = prod.rstrip().split('#')
    if minimo <= float(prod[3]) <= maximo:
        dicionario[prod[0]] = {'Descrição': prod[1], 'Qtd': prod[2], 'Preço': prod[3]}
arquivo.close()
# print(dicionario)
dicionario = {k: v for k, v in sorted(dicionario.items())}
for k, v in dicionario.items():
    print(f'Código: {k:10s}Descrição: {dicionario[k]["Descrição"]:10s} Qtd: {int(dicionario[k]["Qtd"]):4d}\
     Preço: {float(dicionario[k]["Preço"]):2f}')
