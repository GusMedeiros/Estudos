from os import remove, rename


def mostrar(arq):
    for lin in arq:
        print(lin, end='')
    arq.close()
    return None


def inverter(arq, palav, nm):
    novoArq = open(nm + 'Temp', 'w')
    for lin in arq:
        if palav not in lin:
            novoArq.write(lin)
        else:
            ultima = False
            lin = lin.rstrip().split()
            for ind in range(len(lin)):
                if lin[ind] != palav:
                    novoArq.write(lin[ind])
                else:
                    novoArq.write(lin[ind][::-1])
                if ind != len(lin)-1:
                    novoArq.write(' ')
                else:
                    novoArq.write('\n')
    arq.close()
    novoArq.close()
    remove(nm)
    rename(nm + 'Temp', nm)
    return None


# main
nome = input()
palavra = input()
arquivo = open(nome, 'r')
print(f'Arquivo {nome} antes das inversões de {palavra}:')
mostrar(arquivo)
arquivo = open(nome, 'r')
inverter(arquivo, palavra, nome)
print(f'Arquivo {nome} após as inversões de {palavra}:')
arquivo = open(nome, 'r')
mostrar(arquivo)
# obs: os .close() estão dentro das funções.
