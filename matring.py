def gerarmatring():
    for linha in range(4):
        linha = input()
        if not matring:
            [matring.append([]) for coluna in linha]
        for indice, coluna in enumerate(matring):
            coluna.append(linha[indice])
    return matring


def descriptografarmatring(mat):
    coluna0 = mat[0]
    colunaL = mat[len(mat) - 1]
    lastcolumn = int(''.join(colunaL))
    f = int(''.join(coluna0))
    stringfinal = []
    for coluna in range(1, len(mat) - 1):
        coluna = ''.join(mat[coluna])
        stringfinal += chr((f * int(coluna) + lastcolumn) % 257)
    return ''.join(stringfinal)


matring = []
matriz = gerarmatring()
print(descriptografarmatring(matriz))
