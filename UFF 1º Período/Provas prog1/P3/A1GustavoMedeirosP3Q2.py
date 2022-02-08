def gerarset():
    ent = input().split()
    conj = set()
    while ent:
        conj = conj.union(ent)  # adiciona-se o conteúdo da entrada ao conjunto
        ent = input().split()
    return conj


def mostrarconjunto(conj):
    print('=-=-=-= Palavras do conjunto: =-=-=-=')
    for pal in conj:
        print(pal)
    print('=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=')
    return None


def modificararquivo(conj):
    from os import remove, rename
    pont = '.,!:;()-[]"\n' + "'"  # criamos uma string com as pontuações da lingua portuguesa, que mais tarde será usada
    # para podermos reconhecer a palavra independente da pontuação que a acompanhar.
    nm = input('Insira o nome do arquivo a ser modificado:\n')
    mostrarconteudo(nm, 'antes: ')
    arq = open(nm, 'r', encoding='utf-8')
    arqTemp = open(nm+'Temp', 'w', encoding='utf-8')  # criamos uma cópia temporária do arquivo original
    for lin in arq:
        escr = False  # essa variável será utilizada para sabermos quando nenhuma palavra foi escrita na linha.
        for pal in lin.split():
            if pal.strip(pont) not in conj:
                arqTemp.write(f' {pal}')
                escr = True
        if escr or lin == '\n':
            arqTemp.write('\n')
    arqTemp.close()
    arq.close()
    remove(nm)
    rename(nm+'Temp', nm)
    mostrarconteudo(nm, 'depois: ')
    return None


def mostrarconteudo(nm, time):
    arq = open(nm, 'r', encoding='utf-8')
    print(f'========Arquivo {time}=========')
    for lin in arq:
        lin = lin.rstrip()
        print(lin)
    arq.close()
    return None


# main
conjunto = gerarset()
mostrarconjunto(conjunto)
modificararquivo(conjunto)
