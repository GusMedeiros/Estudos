def calcularmaior(maiorp, cont, inip, fimp):
    tamanhop = fimp-inip
    tamanhomaiorp = maiorp[2] - maiorp[1]
    if cont > maiorp[0]:
        # print(f'cont = {cont} | maiorp = {maiorp}')
        maiorp = [cont, inip, fimp]
    elif cont == maiorp[0] and tamanhop > tamanhomaiorp:
        maiorp = [cont, inip, fimp]
    # print(f'Return {maiorp}')
    return maiorp


def mostrar(tst, maiorp):
    cont, iniciop, fimp = maiorp[0], maiorp[1], maiorp[2]
    print(f'Teste {tst}')
    if cont <= 0:
        print('nenhum', end='\n\n')
    else:
        print(iniciop, fimp, end='\n\n')

# maiorperiodo = [ saldo do periodo, primeira partida do periodo, ultima partida do periodo]
# main
N = int(input())
teste = 0
while N != 0:
    listaSaldos = [None]
    contagem = -51
    maiorPeriodo = [contagem, 1, 1]
    fimPeriodo, inicioPeriodo = 1, 1
    for contador in range(N):
        partida = list(map(int, input().split()))
        saldo = partida[0] - partida[1]
        indiceAtual = len(listaSaldos)
        contagemResultante = saldo + contagem
        # print(f'Saldo = {saldo} | contagem = {contagem} | contagemResultante = {contagemResultante}')
        if saldo > contagemResultante:  # se valer mais a pena recomeçar a contagem
            if saldo > contagem:
                contagem = saldo
                inicioPeriodo, fimPeriodo = indiceAtual, indiceAtual
                # print(f'Contagem = {contagem} | inicioPeriodo = {inicioPeriodo} | fimPeriodo = {fimPeriodo}')
                maiorPeriodo = calcularmaior(maiorPeriodo, contagem, inicioPeriodo, fimPeriodo)
        else:  # if saldo <= contagemResultante  - no caso de valer a pena continuar a contagem
            if contagemResultante >= contagem:
                contagem = contagemResultante
                fimPeriodo = indiceAtual
                maiorPeriodo = calcularmaior(maiorPeriodo, contagem, inicioPeriodo, fimPeriodo)
                # print(f'Contagem = {contagem} | inicioPeriodo = {inicioPeriodo} | fimPeriodo = {fimPeriodo}')
            else:   # if contagemresultante < contagem:
                fimPeriodo = indiceAtual - 1
                contagem = contagemResultante
                maiorPeriodo = calcularmaior(maiorPeriodo, contagem, inicioPeriodo, fimPeriodo)
                # print(f'Contagem = {contagem} | inicioPeriodo = {inicioPeriodo} | fimPeriodo = {fimPeriodo}')
        listaSaldos.append(saldo)
    teste += 1
    mostrar(teste, maiorPeriodo)

    N = int(input())

