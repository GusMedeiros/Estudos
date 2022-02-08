def achardados(arq):
    lisCoron, lisOxf, lisDD = [], [], []
    for linha in arq:
        linha = linha.rstrip().split('#')
        if linha[2] == '1':
            if linha[1] == 'coronavac':
                lisCoron.append(linha)
            else:
                lisOxf.append(linha)
        else:
            lisDD.append(linha)
    return lisCoron, lisOxf, lisDD


def criararquivos(liscoron, lisoxf, lisdd):
    arqlis = []
    mat = [liscoron, lisoxf, lisdd]
    for cont in range(3):
        nomearq = input(f'Insira o nome do {cont+1}º arquivo:\n')
        open(nomearq, 'x')
        arqlis.append(open(nomearq, 'w'))
        for lin in mat[cont]:
            arqlis[cont].write('#'.join(lin) + '\n')
        arqlis[cont] = open(nomearq, 'r')
    return [elem for elem in arqlis]


def mostrararquivo(arq):
    arq.seek(0)
    print(f'Iniciando leitura do arquivo {arq.name}')
    print('========Início Arquivo=========')
    for lin in arq:
        lin = lin.rstrip()
        print(lin)
    print('=========Fim Arquivo===========\n')
    arq.seek(0)
    return None


# main
arquivo = open(input(), 'r')
doseCorona, doseOxford, duasDoses = achardados(arquivo)
arquivo1, arquivo2, arquivo3 = criararquivos(doseCorona, doseOxford, duasDoses)
mostrararquivo(arquivo1)
mostrararquivo(arquivo2)
mostrararquivo(arquivo3)
