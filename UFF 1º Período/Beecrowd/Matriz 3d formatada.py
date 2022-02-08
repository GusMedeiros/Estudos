def gerarmatrizvazia(qtdplan, qtdlin, qtdcol):
    mat = []
    for plan in range(qtdplan):
        mat.append([])
        for lin in range(qtdlin):
            mat[plan].append([])
            for col in range(qtdcol):
                mat[plan][lin].append([])
    return mat


def preenchermatriz(mat, valmin, valmax):
    from random import randrange
    for plan in range(len(mat)):
        for lin in range(len(mat[0])):
            for col in range(len(mat[0][0])):
                mat[plan][lin][col] = randrange(valmin, valmax+1)
    return mat


def mostrarmatriz(mat, maiorabs):
    print('Conteúdo da Matriz:')
    for plan in range(len(mat)):
        print(f'Plano {plan+1}')
        for lin in range(len(mat[0])):
            for col in range(len(mat[0][0])):
                if col == len(mat[0][0])-1:
                    print(f'{mat[plan][lin][col]:{len(str(maiorabs))}d}')
                    if lin == len(mat[0])-1:
                        print()
                else:
                    print(f'{mat[plan][lin][col]:{len(str(maiorabs))}d}', end=" ")
    return None


def mediavalores(mat):
    soma = 0
    qtdnum = 0
    for plan in range(len(mat)):
        for lin in range(len(mat[0])):
            for col in range(len(mat[0][0])):
                soma += mat[plan][lin][col]
                qtdnum += 1
    return soma / qtdnum


def maiorvalor(mat, valmin):
    maiorval = valmin
    for plan in range(len(mat)):
        for lin in range(len(mat[0])):
            for col in range(len(mat[0][0])):
                if mat[plan][lin][col] > maiorval:
                    maiorval = mat[plan][lin][col]
    return maiorval


def maiorabsoluto(mat, valmin, valmax):
    maiorcomsinal = 0
    maiorabs = 0
    for plan in range(len(mat)):
        for lin in range(len(mat[0])):
            for col in range(len(mat[0][0])):
                if abs(mat[plan][lin][col]) > maiorabs:
                    maiorabs = abs(mat[plan][lin][col])
                    maiorcomsinal = mat[plan][lin][col]
    return maiorcomsinal


def mostrarocorrencias(mat, maiorval):
    print(f'Maior valor na matriz: {maiorval}')
    print('Posições em que o maior valor ocorre:')
    for plan in range(len(mat)):
        for lin in range(len(mat[0])):
            for col in range(len(mat[0][0])):
                if mat[plan][lin][col] == maiorval:
                    print(f'    Plano {plan}, Linha {lin}, Coluna {col}')
    return None


qtdPlanos, qtdLinhas, qtdColunas = map(int, input().split())
valMinimo, valMaximo = map(int, input().split())
matriz = gerarmatrizvazia(qtdPlanos, qtdLinhas, qtdColunas)
matriz = preenchermatriz(matriz, valMinimo, valMaximo)

maiorValor = maiorvalor(matriz, valMinimo)
maiorAbsoluto = maiorabsoluto(matriz, valMinimo, valMaximo)
mostrarmatriz(matriz, maiorAbsoluto)

print(f'Média dos valores: {mediavalores(matriz):.1f}', end='\n\n')
mostrarocorrencias(matriz, maiorValor)
