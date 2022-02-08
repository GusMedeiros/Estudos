def montarlistas():
    listaNumeros = []
    quantidadeValores = int(input())
    numerosUnicos = []
    for contador in range(quantidadeValores):
        numeroInserido = int(input())
        listaNumeros.append(numeroInserido)
        if numeroInserido not in numerosUnicos:
            numerosUnicos.append(numeroInserido)
    numerosUnicos.sort()
    return [numerosUnicos, listaNumeros]

# main

unicos, todos = montarlistas()
for element in unicos:
    frequencia = todos.count(element)
    print('%d aparece %d vez(es)' % (element, frequencia))
