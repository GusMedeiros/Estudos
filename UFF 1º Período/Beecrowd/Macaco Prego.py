def intersecaointervalos(min1, max1, min2, max2):
    if min2 > max1 or min1 > max2:
        return None
    else:
        return max(min1, min2), min(max1, max2)


def intersecaoretangulos(retatual, ret):
    xMinAtual, xMaxAtual = retatual[0], retatual[2]
    yMaxAtual, yMinAtual = retatual[1], retatual[3]
    xMinRet, xMaxRet = ret[0], ret[2]
    yMaxRet, yMinRet = ret[1], ret[3]
    intersecaoHorizontal = intersecaointervalos(xMinAtual, xMaxAtual, xMinRet, xMaxRet)
    intersecaoVertical = intersecaointervalos(yMinAtual, yMaxAtual, yMinRet, yMaxRet)
    if intersecaoHorizontal and intersecaoVertical:
        return intersecaoHorizontal[0], intersecaoVertical[1], intersecaoHorizontal[1], intersecaoVertical[0]
    return None  # se chegou até aqui n tem intersecao


# main
N = int
intersecao = None
teste = 1
while N != 0:
    retangulos = intersecao = []
    N = int(input())
    if N != 0:
        for contador in range(N):
            entrada = input()
            retangulo = list(map(int, entrada.split()))
            if contador == 0:
                intersecao = retangulo
            if intersecao:
                intersecao = intersecaoretangulos(intersecao, retangulo)
        print(f'Teste {teste}')
        if intersecao:
            print(f'{intersecao[0]} {intersecao[1]} {intersecao[2]} {intersecao[3]}', end='\n\n')
        else:
            print('nenhum', end='\n\n')
        teste += 1
