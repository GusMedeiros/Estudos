quantidade = int(input())
for i in range(quantidade):
    metade1 = ''
    metade2 = ''
    texto = input()
    for char in texto[:(len(texto)//2)]:
        metade1 += char
    metade1 = metade1[::-1]
    #print(metade1,'| len =', len(metade1))
    for char2 in texto[(len(texto)//2):]:
        metade2 += char2
    metade2 = metade2[::-1]
    #print(metade2,'| len =', len(metade2))
    print(metade1 + metade2)
