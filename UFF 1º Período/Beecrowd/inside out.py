senha = int(input())
while senha != 2002:
    senha = int(input())
    if senha != 2002:
        print('Senha Invalida')
if senha == 2002:
    print('Acesso Permitido')
