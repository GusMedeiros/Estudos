# subprog
def gerarRegioes(n):
    reg = []
    for j in range(n):
        reg.append(j+1)
    return reg


def agruparInputs():
    lista = list()
    n = int(input())
    while 13 <= n <= 100:
        lista.append(n)
        n = int(input())
    return lista


# main
resultados = list()
entradas = agruparInputs()
for i in entradas: # pra cada resposta
    jumporiginal = 1
    regioesoriginais = gerarRegioes(i)
    m = 0
    while m == 0: # pra cada jump possivel
        index = 0
        removidos = list()
        regioes = regioesoriginais.copy()
        jump = jumporiginal
        while len(regioes) != 1:
            removidos.append(regioes[index])
            regioes.remove(regioes[index])
            # print(regioes)
            # print('jump =', jump)
            if jumporiginal > len(regioes):# se jump for maior que lista
                jump = jumporiginal % len(regioes)
            if index+jump <= len(regioes):# se não passa a parede
                if jump == index == 0:
                    index = len(regioes)-1
                else:
                    index += jump -1
            else: # se passa a parede
                index = jump - (len(regioes) - index) -1
        if regioes[0] == 13:
            resultados.append(jumporiginal)
            m = 1
        else:
            jumporiginal += 1
for b in resultados:
    print(b)
