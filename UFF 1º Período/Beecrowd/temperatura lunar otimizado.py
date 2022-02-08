N, M = map(int, input().split())
testeAtual = 0
while N != 0 and M != 0:
    listaN = []
    listaMedias = []
    testeAtual += 1
    soma = 0
    # seção que calcula as médias nos intervalos
    for contador in range(1, N+1):  # repetir 1 vez pra cada N
        entrada = int(input())
        listaN.append(entrada)
        soma += entrada  # acumula a entrada TODA vez.
        if len(listaN) == M:  # se já tiver somado M números.
            listaMedias.append(int(soma/M))  # salva a media truncada
            soma -= listaN[0]  # subtrai o número mais antigo
            listaN.remove(listaN[0])  # abre espaço pro proximo numero
    listaMedias.sort()
    # print(listaMedias)
    # fim da seção
    print(f'Teste {testeAtual}')
    print(listaMedias[0], listaMedias[len(listaMedias)-1], end='\n\n')
    N, M = map(int, input().split())
