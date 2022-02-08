def listarpontos(arq):
    pts = []
    for lin in arq:
        pts.append(list(map(float, lin.split())))
    return pts


def distancia(pt1, pt2):
    return ((pt1[0] - pt2[0])**2 + (pt1[1] - pt2[1])**2)**(1/2)


def ponto_diferente(pt, lis):
    for pt2 in lis:
        if pt != pt2:
            return pt2
    return None


def mostrarpontos(lis):
    for indice in range(len(lis)):  # for para mostrar o resultado, com português correto:
        if indice != len(lis) - 1:  # casos separados por vírgula/e
            if indice != len(lis) - 2:  # casos separados por vírgula apenas
                print(f'({str(lis[indice])[1:-1]}), ', end='')
            else:  # casos separados por e apenas
                print(f'({str(lis[indice])[1:-1]}) e ', end='')
        else:  # último caso, caso de ponto final.
            print(f'({str(lis[indice])[1:-1]}).')
    return None


def maior_e_menor_distancia(pt, lis):
    maiordist, ptsmaisdist = 0, []
    pt2 = pt2inicial = ponto_diferente(pt, lis)
    menordist, ptsmenosdist = distancia(pt, pt2), [pt2]
    for pt2 in lis:   # compararemos com cada ponto da lista de pontos
        dist = distancia(pt, pt2)  # coleta da distancia candidata
        # comparação para maior distância
        if dist > maiordist:  # se for maior, overwrite
            maiordist = dist
            ptsmaisdist = [pt2]
        elif dist == maiordist:  # se for igual, listar pontos empatantes
            ptsmaisdist.append(tuple(pt2))
        # comparação para menor distância
        if dist < menordist and pt2 != pt:   # importante testar se pontos diferentes, senão a distância seria 0 sempre
            menordist = dist
            ptsmenosdist = [pt2]
        elif menordist == dist and pt2 != pt2inicial:
            ptsmenosdist.append(tuple(pt2))
    return maiordist, ptsmaisdist, menordist, ptsmenosdist


# principal
arquivo = open(input(), 'r')
pontos = listarpontos(arquivo)
arquivo.close()
if pontos and len(pontos) > 1:
    for ponto in pontos:
        print('\033[96m=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-\033[0m')
        dados = maior_e_menor_distancia(ponto, pontos)
        print(f'O(s) pontos mais \033[93mdistantes\033[0m de \033[93m({str(ponto)[1:-1]})\033[0m é/são: ', end='')
        mostrarpontos(dados[1])
        print(f'A distância entre eles é de {dados[0]:.2f}.')
        print()
        print(f'O(s) pontos mais \033[93mpróximos\033[0m de \033[93m({str(ponto)[1:-1]})\033[0m é/são: ', end='')
        mostrarpontos(dados[3])
        print(f'A distância entre eles é de {dados[2]:.2f}.')
elif pontos and len(pontos) == 1:
    print(f'Como o arquivo só tem um ponto, o ponto mais e menos distante é ele mesmo {pontos[0]})')
    print('A maior e menor distância, consequentemente, será 0.')
else:
    print('Arquivo sem pontos!!!')
