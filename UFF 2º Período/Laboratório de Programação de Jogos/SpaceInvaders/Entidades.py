from PPlay.sprite import Sprite


class Enemy(Sprite):
    matriz = []
    leftmost_i = 0
    leftmost_j = 0
    rightmost_i = 0
    rightmost_j = int
    upmost_i = 0
    upmost_j = 0
    downmost_i = int
    downmost_j = 0
    alien_width = 62
    alien_height = 46
    qtdcolunas = 0
    qtdlinhas = 0
    caminho_sprite = 'alien.png'
    tempo_acumulado_frames = 0
    velx = 100
    vely = 0
    qtdvivos = 0

    def __init__(self, dificuldade, x=0, y=0):
        super().__init__(self.caminho_sprite, 3)

        self.x = x
        self.y = y

    @classmethod
    def reset(cls):
        cls.matriz = []
        cls.leftmost_i = 0
        cls.leftmost_j = 0
        cls.rightmost_i = 0
        cls.rightmost_j = int
        cls.upmost_i = 0
        cls.upmost_j = 0
        cls.downmost_i = int
        cls.downmost_j = 0
        cls.alien_width = 62
        cls.alien_height = 46
        cls.caminho_sprite = 'alien.png'
        cls.tempo_acumulado_frames = 0
        cls.tempo_acumulado_mover = 0
        cls.colisao = False
        cls.velx = 100
        cls.vely = 0

    @classmethod
    def spawn(cls, dificuldade, colunas, linhas):
        cls.qtdcolunas = colunas
        cls.qtdlinhas = linhas
        cls.downmost_i = linhas - 1
        cls.rightmost_j = colunas - 1
        cls.qtdvivos = colunas * linhas
        from random import randint
        for i in range(linhas):
            cls.matriz.append([])
            for j in range(colunas):
                alien = Enemy(dificuldade)
                alien.set_position(j * alien.width * 1.5, i * alien.height * 1.5)
                alien.set_curr_frame(randint(0, 1))
                cls.matriz[i].append(alien)

    @classmethod
    def desenhar_e_update(cls, delta_time):
        cls.tempo_acumulado_frames += delta_time
        for i, linha in enumerate(cls.matriz):
            for j, alien in enumerate(linha):
                if alien:
                    alien.x += cls.velx * delta_time
                    alien.y += cls.vely
                    alien.draw()
                    if cls.tempo_acumulado_frames > 0.5:
                        if alien.get_curr_frame() != 2:
                            alien.set_curr_frame((alien.get_curr_frame() + 1) % 2)
                        else:
                            linha[j] = False
                            cls.qtdvivos -= 1
                            '''print(f'matei o {i},{j}')'''
                            if alien:
                                if i == cls.leftmost_i and j == cls.leftmost_j:
                                    cls.substituir_extremo(4)
                                    '''print("Troquei o leftmost")
                                    print(cls.leftmost_i, cls.leftmost_j)'''
                                if i == cls.rightmost_i and j == cls.rightmost_j:
                                    cls.substituir_extremo(6)
                                    '''print("Troquei o rightmost")
                                    print(cls.rightmost_i, cls.rightmost_j)'''
                                if i == cls.downmost_i and j == cls.downmost_j:
                                    cls.substituir_extremo(2)
                                    '''print("Troquei o downmost")
                                    print(cls.downmost_i, cls.downmost_j)'''
                                if i == cls.upmost_i and j == cls.upmost_j:
                                    cls.substituir_extremo(8)
                                    '''print("Troquei o upmost")
                                    print(cls.upmost_i, cls.upmost_j)'''

        if cls.tempo_acumulado_frames > 0.5:
            cls.tempo_acumulado_frames = 0

    @classmethod
    def substituir_extremo(cls, extremo: int):
        """Função que deve ser chamada quando um alien de referência morrer, para substituí-lo.
        O parâmetro extremo indica qual extremo deseja substituir.
        Ele é análogo ao teclado numérico: 4 é o leftmost, 6 rightmost, 8 upmost, 2 downmost."""

        if extremo == 4:  # leftmost
            # Achar o alien mais à esquerda requer achar a coluna de menor índice.
            menor_j = 10000  # portanto, inicializamos com um valor alto, para garantir que será trocado.
            '''preferencialmente, esse alien não estará embaixo, que estatisticamente tem mais chances de ser atingido,
            forçando uma troca desnecessária. Portanto, caso empatem no J (coluna), escolheremos o de i menor.'''
            menor_i = 10000 # portanto, inicializamos com um valor alto, para garantir que será trocado.
            for i, linha in enumerate(cls.matriz):
                for j, alien in enumerate(linha):
                    if alien:
                        if j < menor_j:
                            menor_i = i
                            menor_j = j
                        elif j == menor_j:  # desempate pelo mais acima, ou seja, menor i.
                            if i < menor_i:
                                menor_i = i
            cls.leftmost_i = menor_i
            cls.leftmost_j = menor_j
            # cls.matriz[menor_i][menor_j].image = pygame.image.load('alienred.png').convert_alpha()

        elif extremo == 6:  # rightmost
            # Achar o alien mais à direita requer achar a coluna de maior índice.
            maior_j = -1  # portanto, inicializamos com um valor negativo, para garantir que será trocado.
            '''preferencialmente, esse alien não estará embaixo, que estatisticamente tem mais chances de ser atingido,
            forçando uma troca desnecessária. Portanto, caso empatem no J (coluna), escolheremos o de i menor.'''
            menor_i = 10000  # portanto, inicializamos com um valor alto, para garantir que será trocado.
            for i, linha in enumerate(cls.matriz):
                for j, alien in enumerate(linha):
                    if alien:
                        if j > maior_j:
                            menor_i = i
                            maior_j = j
                        elif maior_j == j:  # desempate pelo mais acima, ou seja, menor i.
                            if i < menor_i:
                                menor_i = i
            cls.rightmost_i = menor_i
            cls.rightmost_j = maior_j
            # cls.matriz[menor_i][maior_j].image = pygame.image.load('alienred.png').convert_alpha()
        elif extremo == 2:  # downmost
            # Achar o alien mais abaixo requer achar a linha de maior índice.
            maior_i = -1  # portanto inicializamos negativo para garantir que será trocado.
            '''preferencialmente, esse alien não estará ao meio, que estatisticamente tem mais chances de ser atingido,
            forçando uma troca desnecessária. Portanto, caso empatem no i (coluna), escolheremos o de j maior.'''
            maior_j = -1  # inicializamos negativo pelo mesmo motivo acima.
            for i, linha in enumerate(cls.matriz):
                for j, alien in enumerate(linha):
                    if alien:
                        if i > maior_i:
                            maior_i = i
                            maior_j = j
                        elif i == maior_i:  # desempate dando prioridade ao mais à direita.
                            if j > maior_j:
                                maior_j = j
            cls.downmost_i = maior_i
            cls.downmost_j = maior_j
            # cls.matriz[maior_i][maior_j].image = pygame.image.load('alienred.png').convert_alpha()

        elif extremo == 8:  # upmost
            # Achar o alien mais acima requer achar a linha de menor índice.
            menor_i = 10000  # portanto, inicializamos com um valor alto para garantir que será mudado.
            '''preferencialmente, esse alien não estará ao meio, que estatisticamente tem mais chances de ser atingido,
            forçando uma troca desnecessária. Portanto, caso empatem no i (coluna), escolheremos o de j menor.'''
            menor_j = 10000  # portanto, inicializamos com um valor alto para garantir que será mudado.
            for i, linha in enumerate(cls.matriz):
                for j, alien in enumerate(linha):
                    if alien:
                        if i < menor_i:
                            menor_i = i
                            menor_j = j
                        elif menor_i == i:  # caso a altura/linha empate, preferimos o mais à esquerda.
                            if j < menor_j:
                                menor_j = j
            cls.upmost_i = menor_i
            cls.upmost_j = menor_j
            # cls.matriz[menor_i][menor_j].image = pygame.image.load('alienred.png').convert_alpha()

    @classmethod
    def desenhar(cls):
        for linha in cls.matriz:
            for alien in linha:
                if alien:
                    alien.draw()

    @classmethod
    def colisao_parede(cls, width, delta_time):
        for linha in cls.matriz:
            if linha:
                primeiro_alien = cls.matriz[cls.leftmost_i][cls.leftmost_j]
                ultimo_alien = cls.matriz[cls.rightmost_i][cls.rightmost_j]
                if primeiro_alien.x < 0 or ultimo_alien.x + ultimo_alien.width >= width:
                    cls.velx *= -1
                    cls.vely = primeiro_alien.height/2
                    cls.mover(delta_time, False)
                    return
        cls.vely = 0

    @classmethod
    def mover(cls, delta_time, moverY: bool):
        for linha in cls.matriz:
            for alien in linha:
                if alien:
                    alien.x += cls.velx * delta_time
                    if moverY:
                        alien.y += cls.vely

    @classmethod
    def checar_hit(cls, lista_tiro):
        if cls.qtdvivos <= 0:
            return 10
        # encurtando nomes de índices necessários
        d_i = cls.downmost_i
        d_j = cls.downmost_j
        u_i = cls.upmost_i
        u_j = cls.upmost_j
        l_i = cls.leftmost_i
        l_j = cls.leftmost_j
        r_i = cls.rightmost_i
        r_j = cls.rightmost_j
        # encurtando variável das coordenadas necessárias
        leftmost_x = cls.matriz[l_i][l_j].x
        rightmost_x = cls.matriz[r_i][r_j].x
        upmost_y = cls.matriz[u_i][u_j].y
        downmost_y = cls.matriz[d_i][d_j].y
        alien_distance_horizontal = cls.alien_width * 1.5
        alien_distance_vertical = cls.alien_height * 1.5
        # inicializando qtdhits
        qtdhits = 0
        hit_j = []
        for t, tiro in enumerate(lista_tiro):
            if tiro.x + tiro.width > leftmost_x and tiro.x < rightmost_x + alien_distance_horizontal \
                    and tiro.y + tiro.height > upmost_y and tiro.y < downmost_y + alien_distance_vertical:
                hit_j.append(int(l_j + abs(tiro.x - leftmost_x) // alien_distance_horizontal))
                hit_j.append(int(l_j + abs(tiro.x + tiro.width - leftmost_x) // alien_distance_horizontal))
                hit_i = int(u_i + abs(tiro.y - upmost_y) // alien_distance_vertical)
                if hit_i >= cls.qtdlinhas:
                    continue
                for j in hit_j:
                    alien = None
                    if j < cls.qtdcolunas:
                        alien = cls.matriz[hit_i][j]
                    if alien:
                        if tiro.collided(alien):
                            print(f'X do tiro: {tiro.x}, X do alien: {alien.x}, índice i: {hit_i},'
                                  f' X do leftmost: {leftmost_x}')
                            alien.set_curr_frame(2)
                            lista_tiro.pop(t)
                            qtdhits += 1
                            break
        return qtdhits


class Player(Sprite):
    caminho_sprite = 'Player.png'

    def __init__(self, dificuldade, x=0, y=0):
        super().__init__(self.caminho_sprite)
        self.x = x
        self.y = y
        if dificuldade == 'Fácil':
            self.velX = 600
            self.tiros_delay = 0.00001
        elif dificuldade == 'Médio':
            self.velX = 450
            self.tiros_delay = 0.25
        else:
            self.velX = 300
            self.tiros_delay = 0.5


class Tiro:
    lista = []
    velY = 600

    def __init__(self, sprite, mid_x_player, y_player):
        self.sprite = sprite
        self.sprite.x = mid_x_player - sprite.width/2
        self.sprite.y = y_player - self.sprite.height
        self.lista.append(sprite)

    @classmethod
    def update_and_draw(cls, janela, ranking):
        for tiro in cls.lista:
            tiro.y -= cls.velY * janela.delta_time()
            if tiro.y + tiro.height <= 0:
                cls.lista.remove(tiro)
            else:
                tiro.draw()

    @classmethod
    def draw(cls):
        for tiro in cls.lista:
            tiro.draw()
