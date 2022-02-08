def mostrarconteudo(arq):
    print('========Início Arquivo=========')
    for lin in arq:
        lin = lin.rstrip()
        print(lin)
    print('=========Fim Arquivo===========')
    arq.seek(0)
    return None


def maiordistancia(arq):
    pts = []
    maiordist = None
    for lin in arq:
        lin = list(map(float, lin.rstrip().split()))
        pts.append(lin)
    arq.seek(0)
    for p1 in pts:
        for p2 in pts:
            dist = achardistancia(p1, p2)
            if maiordist:
                if dist > maiordist:
                    ptsmaisdistantes = (p1, p2, dist)
            else:
                maiordist = dist
                ptsmaisdistantes = (p1, p2, dist)
    return ptsmaisdistantes


def achardistancia(pt1, pt2):
    pt1x, pt1y = pt1[0], pt1[1]
    pt2x, pt2y = pt2[0], pt2[1]
    dist = ((pt1x - pt2x)**2+(pt1y - pt2y)**2)**(1/2)
    return dist


# main
nomearquivo = input('Insira o nome do arquivo (com extensão):\n')
arquivo = open(nomearquivo, 'r')
mostrarconteudo(arquivo)
ponto1, ponto2, distancia = maiordistancia(arquivo)
ponto1X, ponto1Y, ponto2X, ponto2Y = ponto1[0], ponto1[1], ponto2[0], ponto2[1]
print(f'Pontos mais distantes: ({ponto1X}, {ponto1Y}) e ({ponto2X}, {ponto2Y}).'
      f' Sua distância é de: {distancia:.2f}')
