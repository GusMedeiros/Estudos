def gerartamanhoseindices(list):
    siz = []
    for ind in range(len(list)):
        siz.append([len(list[ind]), ind])
    return siz


def ordenartamanhoseindices(list):
    a, b = 0, 0
    deslocados = 1
    while deslocados != 0:
        deslocados = 0
        for ind in range(len(list) - 1):
            a = list[ind][0]
            a1 = list[ind][1]
            b = list[ind + 1][0]
            b1 = list[ind + 1][1]
            if a < b:
                list[ind][0] = b
                list[ind][1] = b1
                list[ind + 1][0] = a
                list[ind + 1][1] = a1
                deslocados += 1
    return list


def gerarindices(lis):
    novalist = []
    for elem in lis:
        novalist.append(elem[1])
    return novalist


def ordenarstrings(liststr):
    sizs = gerartamanhoseindices(liststr)
    sizs = ordenartamanhoseindices(sizs)
    inds = gerarindices(sizs)
    stringsord = [liststr[ind] for ind in inds]
    return stringsord


# main
N = int(input())
for contador in range(N):
    strings = input().split()
    stringsordenadas = ordenarstrings(strings)
    for indice in range(len(stringsordenadas)):
        if indice != len(stringsordenadas)-1:
            print(stringsordenadas[indice], end=' ')
        else:
            print(stringsordenadas[indice])
