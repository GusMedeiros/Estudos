def acharmaior(arq):
    maiorint = None
    for lin in arq:
        lin = list(map(int, lin.split()))
        for num in lin:
            if maiorint:
                if num > maiorint:
                    maiorint = num
            else:
                maiorint = num
    return maiorint


# main
nomearquivo = input('Insira o nome do arquivo (com extensão):\n')
arquivo = open(nomearquivo, 'r')
print(acharmaior(arquivo))
