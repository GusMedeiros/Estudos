def testarsubstring(sub, main):
    subaux = ''
    i = 0
    for ind in range(len(main)):
        mainTemp = main[ind]
        if i < len(sub):
            if sub[i] == mainTemp:
                subaux += mainTemp
                i += 1
        elif subaux == sub:
            return 'Yes'
        else:
            return 'No'
    if subaux == sub:
        return 'Yes'
    else:
        return 'No'


N = int(input())
for caso in range(N):
    stringprincipal = input()
    Q = int(input())
    for querie in range(Q):
        substring = input()
        print(testarsubstring(substring, stringprincipal))
