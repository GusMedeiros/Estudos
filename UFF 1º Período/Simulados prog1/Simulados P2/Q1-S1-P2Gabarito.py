# Programa - P2Q1
# Subprogramas
def mostra(nm, msg):
    dados = open(nm, "r")
    print(msg)
    for linha in dados:
        x,y = map(int, linha.split())
        print(x,y)
    dados.close()
    print()
    return None


def naoDentro(ctrX,ctrY, raio, xP,yP):
    distancia = ((ctrX-xP)**2+(ctrY-yP)**2)**.5
    return raio < distancia


def remover(cX, cY, raio, nm):
    from os import remove, rename
    dados = open(nm, "r")
    temp = open(nm+"$$$", "w")
    for linha in dados:
        x, y = map(int, linha.split())
        if naoDentro(cX,cY,raio,x,y):
            temp.write(linha)
    temp.close()
    dados.close()
    remove(nm)
    rename(nm+"$$$", nm)
    return None


# Principal
nome = input()
centroX, centroY, raioCentro = map(int, input().split())
mostra(nome, "Pontos do Arquivo %s antes das remoções:"%nome)
remover(centroX, centroY, raioCentro, nome)
mostra(nome, "Pontos do Arquivo %s depois das eventuais remoções:"%nome)
