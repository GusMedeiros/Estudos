# joseph's cousin

#   sub
def proximoprimo(numero):
    if numero == None:
        numero = 1
    # passar pro proximo numero
    while True:
        if numero == 2:
            return 3
        contdivisores = 0
        divisor = int
        primo = numero
        if numero % 2 == 0:
            numero += 1
        else:
            numero += 2
    # testar se numero é primo
        for counter in range(int(numero ** (1/2)), 1, -1):
            divisor = counter
            if numero % divisor == 0:
                break
            if divisor == 2:
                primo = numero
                return primo


def gerarlista(n):
    reg = []
    for j in range(n):
        reg.append(j+1)
    return reg


def eleRemov(lis, m, lastIndex):
    index = lastIndex
    while (index + m-1) > len(lis)-1: # enquanto indice resultante passar da parede
        if m > len(lis): # se a lista for menor que o m, alterar m
            m = m % len(lis)
        else: # quando passa a parede normalmente
            index = (index + m-1) % len(lis)
            return index
    # fora do while, logo index+m nao passa da parede
    index += m -1
    return index
    # lembrar de usar indice-1 no programa depois de remover


#   main
entrada = int
entradas = list()
while entrada != 0: # pedir entradas e armazenar até entrada ser 0
    entrada = int(input())
    entradas.append(entrada)
# print(entradas)
for element in entradas: # pra cada entrada:
    ultimo = 0
    jump = 2
    lista = gerarlista(element)
    while len(lista) > 1: #enquanto tiver mais de um vivo
        # print(lista)
        # print('jump=',jump)
        indicekill = eleRemov(lista, jump, ultimo)
        # print('indicekill=',indicekill)
        lista.remove(lista[indicekill])
        jump = proximoprimo(jump)
        ultimo = indicekill
    # print(lista)
    if lista:
        print(lista[0])
