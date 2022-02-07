def moverrobo():
    x, n = int(), int(input())
    instrlist, positlist = [], []
    for cont in range(n):
        instr = input()
        while instr != 'LEFT' and instr != 'RIGHT':
            linsplit = instr.split()
            instr = int(linsplit[len(linsplit)-1]) - 1
            instr = instrlist[instr]
        if instr == 'LEFT':
            x -= 1
        else:
            x += 1
        instrlist.append(instr)
    return x


# main
qtdTestes = int(input())
for teste in range(1, qtdTestes+1):
    print(moverrobo())
