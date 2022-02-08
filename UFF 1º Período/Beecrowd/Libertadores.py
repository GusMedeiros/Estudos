def acharvencedor(t1, t2):
    if time1[0] > time2[0]:
        return 'Time 1'
    elif time2[0] > time1[0]:
        return 'Time 2'
    elif time1[1] > time2[1]:
        return 'Time 1'
    elif time2[1] > time1[1]:
        return 'Time 2'
    else:
        return 'Penaltis'


# main
N = int(input())
listaprints = []
for contador in range(N):
    jogo = input().split()
    time1 = [int(jogo[0]), 0]  # [placar, golsforadecasa]
    time2 = [int(jogo[2]), int(jogo[2])]
    jogo = input().split()
    time1[0], time1[1] = time1[0] + int(jogo[2]), int(jogo[2])  # placar soma score do jogo 2, gols fora de cassa recebe score jogo 2
    time2[0] += int(jogo[0])  # soma ao placar do time 2 o score do jogo 2
    listaprints.append(acharvencedor(time1, time2))
for elem in listaprints:
    print(elem)
