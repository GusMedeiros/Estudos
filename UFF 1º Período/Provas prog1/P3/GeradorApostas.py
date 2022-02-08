from random import randint


def mostrarconteudo(arq):
    print('========Início Arquivo=========')
    for lin in arq:
        lin = lin.rstrip()
        print(lin)
    print('=========Fim Arquivo===========')
    arq.close()
    return None


arquivo = open('Apostas.txt', 'w')
quantidade = int(input('Insira quantas apostas quer:'))
for c in range(quantidade):
    linha = (str(randint(10**9, 10**10-1)))
    for n in range(6):
        linha += f'#{randint(0,9)}'
    linha += '\n'
    arquivo.write(linha)
arquivo.close()
mostrarconteudo(open('Apostas.txt', 'r'))
