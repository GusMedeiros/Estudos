# subprograma
def somar(lista):
    for u in range(len(lista)):
        if lista[u].islower() or lista[u].isupper():
            lista[u] = ord(lista[u])
            lista[u] += 3
            lista[u] = chr(lista[u])
    return lista


def somartruncado(lista):
    for u in range(len(lista)//2, len(lista)):
        lista[u] = ord(lista[u])
        lista[u] -= 1
        lista[u] = chr(lista[u])
    return lista


def criptografar(qtd):
    textos = list()
    for i in range(qtd):
        textos.append(input())
        caracteres = list(textos[i])
        caracteres = somar(caracteres)
        caracteres = list(reversed(caracteres))
        caracteres = somartruncado(caracteres)
        caracteres = "".join(caracteres)
        print(caracteres)
    return None


# programa principal
qtdlinhas = int(input())
criptografar(qtdlinhas)
