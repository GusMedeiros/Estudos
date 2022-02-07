# sub
def gerarmatriz(ordem):
    mat = []
    for lin in range(ordem):
        mat.append([])
        for col in range(ordem):
            mat[lin].append(abs(lin-col) + 1)
    return mat


def mostrarmatriz(mat):
    for lin in range(len(mat)):
        for col in range(len(mat)):
            if col == len(mat)-1:
                print('%3d' % mat[lin][col])
            else:
                print('%3d' % mat[lin][col], end=" ")
    if len(mat) != 0:
        print()
    return None
# main


entrada = int
while entrada != 0:
    entrada = int(input())
    matriz = gerarmatriz(entrada)
    mostrarmatriz(matriz)
