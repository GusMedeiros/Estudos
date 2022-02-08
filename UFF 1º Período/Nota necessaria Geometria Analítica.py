formativas = []
somativa = []
print('Bem-vindo à calculadora de média de cálculo!!')
print('Insira as notas das suas formativas:')
for c in range(9):
    formativas.append(float(input('\t')))
formativas.remove(min(formativas))
print('Ótimo, agora insira a nota da suas somativa 1:')
somativa = float(input('\t'))
formativas = sum(formativas)/8
print('Se você fez a tarefa bônus, digite S, senão, digite qualquer outra coisa')
extra = input('\t')
if extra == 'S':
    somativa2 = -2*(0.35 * formativas + 0.65 * somativa/2 - 5.5)/0.65
    media = 0.35 * formativas + 0.65 * (somativa + somativa2)/2
else:
    somativa2 = -2*(0.35 * formativas + 0.65 * somativa/2 - 6)/0.65
    media = 0.35 * formativas + 0.65 * (somativa + 10)/2
if somativa2 <= 0:
    print('Você já passou, mesmo que tire zero!!!')
elif somativa2 <= 10:
    print(f'Você precisa tirar: {somativa2}')
elif media >= 4:
    if extra == 'S':
        somativa2 = -2 * (0.35 * formativas + 0.65 * somativa / 2 - 3.5) / 0.65
    else:
        somativa2 = -2 * (0.35 * formativas + 0.65 * somativa / 2 - 4) / 0.65
    print(f'''Infelizmente não vai dar pra você passar direto.
    Entretanto, se você tirar {somativa2}, você consegue ficar de VS.''')
elif media < 4:
    print(f'Infelizmente você reprovou, pois para ficar de vs você precisaria tirar {somativa2}')
