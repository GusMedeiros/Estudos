alfabetoCriptografado = input()
alfabeto = 'abcdefghijklmnopqrstuvwxyz'
mensagem = input()
mensagemDecripto = []
for letra in mensagem:
    indice = alfabetoCriptografado.index(letra)
    mensagemDecripto.append(alfabeto[indice])
mensagemDecripto = ''.join(mensagemDecripto)
print(mensagemDecripto)
