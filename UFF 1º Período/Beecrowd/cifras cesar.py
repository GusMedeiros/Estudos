qtdTestes = int(input())
for i in range(qtdTestes):
    stringNova = ''
    string = input()
    deslocamento = int(input())
    for element in string: # por string
        letra = element
        idLetra = ord(letra)
        # se passar parede
        if idLetra-deslocamento < 65:
            # se pulo maior que alfabeto
            if deslocamento > 26:
                deslocamento %= 26
            else:   # se passar parede normalmente
                idLetra = idLetra - deslocamento + 26
        else:
            idLetra -= deslocamento     # se nao passar parede
        letra = chr(idLetra)
        stringNova += letra
    print(stringNova)
