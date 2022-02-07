expressao = '1'
while True:
    try:
        expressao = input()
        contador = 0
        for char in expressao:
            if char == ')':
                contador -= 1
            elif char == '(':
                contador += 1
            if contador < 0:
                break
        if contador == 0:
            print('correct')
        else:
            print('incorrect')
    except EOFError:
        break