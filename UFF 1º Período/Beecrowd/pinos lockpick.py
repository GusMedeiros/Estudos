total = 0
qtdPinos, altura = map(int, input().split())
pinos = list(map(int, input().split()))
for indice in range(len(pinos)-1):
    distancia = altura - pinos[indice]
    pinos[indice] += distancia
    pinos[indice + 1] += distancia
    total += abs(distancia)
print(total)
