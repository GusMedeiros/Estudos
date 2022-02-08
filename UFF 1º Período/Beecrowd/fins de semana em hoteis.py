resultado = 500001
qtdParticipantes, orcamento, qtdHoteis, qtdSemanas = map(int, input().split())
camasHoteis, precos, hoteisValidos = [], [], []
for contador in range(qtdHoteis):
    hoteisValidos.append(False)
    precos.append(int(input()))
    camasHoteis.append(list(map(int, input().split())))
for contador in range(qtdHoteis):
    for elemento in camasHoteis[contador]:
        if elemento >= qtdParticipantes:
            hoteisValidos[contador] = True
for contador in range(len(hoteisValidos)):
    resultadoNovo = precos[contador] * qtdParticipantes
    if hoteisValidos[contador] is True and resultadoNovo < resultado:
        resultado = precos[contador] * qtdParticipantes
if resultado > orcamento:
    print('stay home')
else:
    print(resultado)
