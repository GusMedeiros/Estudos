maiorpalavra = ''
contaLinhas, maiorLinha = 0, 0
entrada = input()
while entrada != '':
    contaLinhas += 1
    linha = entrada.split()
    for palavra in linha:
        if len(palavra) > len(maiorpalavra):
            maiorpalavra = palavra
            maiorLinha = contaLinhas
    entrada = input()
print(f'Palavra Mais Comprida: {maiorpalavra}')
print(f'Linha da Primeira Ocorrência: {maiorLinha}')
