def gerarligacoes(segmnts, ligs):
    lis = []
    for cont in range(segmnts):
        lis.append([])
    for cont in range(ligs):
        lig1, lig2 = map(int, input().split())
        if lig2 not in lis[lig1 - 1]:
            lis[lig1 - 1].append(lig2)
        if lig1 not in lis[lig2 - 1]:
            lis[lig2 - 1].append(lig1)
    return lis


def bfs(lis):
    visitados, fila = [], []
    for c in range(len(lis)):  # gera lista de visitados com todos não visitados por padrão
        visitados.append(False)
    # bfs em si
    visitados[0] = True  # node 1 foi visitado
    fila.append(1)  # node 1 na fila
    while fila:
        noAtual = fila[0]  # processar o próximo da fila
        visitados[noAtual - 1] = True  # avisando que não é mais pra visitar esse nó
        for elem in lis[noAtual - 1]:  # manipulando o conteúdo do nó (nós adjacentes)
            if elem not in fila and visitados[elem - 1] == False:  # se o node adjacente não estiver na fila e nem
                # já tiver sido visitado
                fila.append(elem)  # nesse caso, colocar na fila pra ser processado.
        fila.remove(fila[0])  # remove o que acabou de ser processado da fila.
    if False in visitados:
        return 'INCOMPLETO'
    else:
        return 'COMPLETO'


# main
N, L = map(int, input().split())
ligacoes = gerarligacoes(N, L)
print(ligacoes)
print(bfs(ligacoes))
