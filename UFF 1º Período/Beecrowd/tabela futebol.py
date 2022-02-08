def acharpontos(lin):
    ptsA, ptsB = 0, 0
    timeA, golsTimeA, timeB, golsTimeB = lin.split('#')
    if golsTimeA > golsTimeB:
        ptsA = 3
    elif golsTimeB > golsTimeA:
        ptsB = 3
    else:
        ptsA, ptsB = 1, 1
    return ptsA, ptsB


def atualizartabela(tab, lin, ptsA, ptsB):
    if lin[0] in tab:
        for ind in range(len(tab)):
            if lin[0] == tab[indice]:
                tab[indice+1] += ptsA
    else:
        tab.append(lin[0])
        tab.append(ptsA)
    if lin[2] in tab:
        for ind in range(len(tab)):
            if lin[2] == tab[indice]:
                tab[indice+1] += ptsB
    else:
        tab.append(lin[2])
        tab.append(ptsB)
    return tab


jogoAtual = 1
listaInputs = []
entrada = input()
tabela = []
while entrada != '':
    linha = entrada.split('#')
    pontosA, pontosB = acharpontos(entrada)
    tabela = atualizartabela(tabela, linha, pontosA, pontosB)
    entrada = input()
    # tabela.append('\n')
    print(f'Após {jogoAtual} jogo(s):')
    for indice in range(0, len(tabela), 2):
        if indice != len(tabela)-1:
            # print(f'Indice = {indice}')
            # print(f'Tabela = {tabela}')
            print(f'    {tabela[indice]} {tabela[indice+1]} ponto(s)')
    print()
    jogoAtual += 1
print(tabela)
