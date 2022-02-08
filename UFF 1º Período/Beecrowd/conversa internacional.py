qtdgrupos = int(input())
for cont in range(qtdgrupos): # pra cada grupo
    tamanhogrupo = int(input())
    linguas = []
    for cont2 in range(tamanhogrupo): # pra cada pessoa
        lingua = input()
        linguas.append(lingua)
    if linguas.count(linguas[0]) == len(linguas):
        print(linguas[0])
    else:
        print('ingles')

