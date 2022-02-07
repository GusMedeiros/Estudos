def converterchave(k, mod):
    return k % mod


# main
N = int(input())
for contador in range(N):
    M, C = map(int, input().split())
    lista = [[] for i in range(M)]
    chaves = list(map(int, input().split()))
    for chave in chaves:
        chaveconvertida = converterchave(chave, M)
        lista[chaveconvertida].append(chave)
    for indice in range(len(lista)):
        print(f'{indice} -> ', end='')
        if lista[indice]:
            for elemento in lista[indice]:
                print(f'{elemento} -> ', end='')
        print('\\')
    if contador != N-1:
        print()
