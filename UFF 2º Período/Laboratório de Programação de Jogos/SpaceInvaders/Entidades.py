from os import getcwd
from random import randint

from PPlay.sprite import Sprite


class Enemy(Sprite):
    boss = None
    vidas_boss = 3
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
    caminho_sprite = f'{getcwd()}\\alien.png'
    caminho_sprite_boss = f'{getcwd()}\\alienred.png'
    tempo_acumulado_frames = 0
    velx = 100
    vely = 0
    qtdvivos = 0
    fase_atual = 0
    fase_maxima = 4
    reload_cooldown = {"Fácil": 8,
                       "Médio": 6,
                       "Difícil": 4}

    def __init__(self, dificuldade, x=0, y=0, force_boss=False):
        if force_boss:  # 5% de chance de spawnar o boss
            super().__init__(self.caminho_sprite_boss, 3)
            Enemy.boss = self
        else:
            super().__init__(self.caminho_sprite, 3)
        self.reload_timer = 0
        self.x = x
        self.y = y

    @classmethod
    def reset(cls):
        cls.boss = None
        cls.matriz = []
        cls.vidas_boss = 3
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
        cls.qtdcolunas = 0
        cls.qtdlinhas = 0
        cls.caminho_sprite = f'{getcwd()}\\alien.png'
        cls.caminho_sprite_boss = f'{getcwd()}\\alienred.png'
        cls.tempo_acumulado_frames = 0
        cls.velx = 100
        cls.vely = 0
        cls.qtdvivos = 0
        cls.fase_atual = 0
        cls.fase_maxima = 4

    @classmethod
    def set_difficulty(cls, dificuldade: str):
        if dificuldade == "Fácil":
            cls.velx = 80
        elif dificuldade == "Médio":
            cls.velx = 100
        else:
            cls.velx = 200

    @classmethod
    def isgameover(cls, player):
        alien_mais_abaixo = cls.matriz[cls.downmost_i][cls.downmost_j]
        if player.vidas == 0 or cls.fase_atual == cls.fase_maxima \
                or alien_mais_abaixo.y + alien_mais_abaixo.height >= player.y:
            return True
        return False

    @classmethod
    def proxima_fase(cls, dificuldade: str):
        cls.velx *= 1.2
        cls.boss = None
        cls.vidas_boss = 3
        cls.spawn(dificuldade, cls.qtdcolunas, cls.qtdlinhas, respawn=True)
        cls.reload_cooldown[dificuldade] *= 0.8
        cls.fase_atual += 1

    @classmethod
    def spawn(cls, dificuldade, colunas, linhas, respawn=False):
        cls.qtdcolunas = colunas
        cls.qtdlinhas = linhas
        cls.upmost_i = cls.rightmost_i = cls.leftmost_i = cls.upmost_j = cls.downmost_j = cls.leftmost_j = 0
        cls.downmost_i = linhas - 1
        cls.rightmost_j = colunas - 1
        cls.qtdvivos = colunas * linhas
        from random import randint
        for i in range(linhas):
            if respawn is False:
                cls.matriz.append([])
            for j in range(colunas):
                if i == linhas - 1 and j == colunas - 1 and cls.boss is None:
                    alien = Enemy(dificuldade, force_boss=True)
                    # /\ se por azar é o último alien e o boss não nasceu, forçamos a nascer agora.
                else:
                    alien = Enemy(dificuldade)
                alien.set_position(j * alien.width * 1.5, i * alien.height * 1.5)
                alien.set_curr_frame(randint(0, 1))
                if respawn is False:
                    cls.matriz[i].append(alien)
                else:
                    cls.matriz[i][j] = alien

    def atirar(self, delta_time):
        deve_atirar = randint(1, 7) == 1
        if self.reload_timer >= 8:
            self.reload_timer = 0
            if deve_atirar:
                Tiro(-1, self.x + self.width / 2, self.y)
        else:
            self.reload_timer += delta_time

    @classmethod
    def desenhar_e_update(cls, delta_time):
        cls.tempo_acumulado_frames += delta_time
        for i, linha in enumerate(cls.matriz):
            for j, alien in enumerate(linha):
                if alien:
                    alien.x += cls.velx * delta_time
                    alien.y += cls.vely
                    alien.draw()
                    if alien.get_curr_frame() != 2:
                        alien.atirar(delta_time)
                    if cls.tempo_acumulado_frames > 0.5:
                        if alien.get_curr_frame() != 2:
                            alien.set_curr_frame((alien.get_curr_frame() + 1) % 2)
                        else:
                            linha[j] = False
                            cls.qtdvivos -= 1
                            if alien:
                                if i == cls.leftmost_i and j == cls.leftmost_j:
                                    cls.substituir_extremo(4)
                                if i == cls.rightmost_i and j == cls.rightmost_j:
                                    cls.substituir_extremo(6)
                                if i == cls.downmost_i and j == cls.downmost_j:
                                    cls.substituir_extremo(2)
                                if i == cls.upmost_i and j == cls.upmost_j:
                                    cls.substituir_extremo(8)

        if cls.tempo_acumulado_frames > 0.5:
            cls.tempo_acumulado_frames = 0

    @classmethod
    def substituir_extremo(cls, extremo: int):
        """Função que deve ser chamada quando um alien de referência morrer, para substituí-lo.
        O parâmetro extremo indica qual extremo deseja substituir.
        Ele é análogo ao teclado numérico: 4 é o leftmost, 6 rightmost, 8 upmost, 2 downmost."""
        if cls.qtdvivos == 1:
            for i, linha in enumerate(cls.matriz):
                for j, alien in enumerate(linha):
                    if alien:
                        cls.rightmost_i = cls.leftmost_i = cls.downmost_i = cls.upmost_i = i
                        cls.rightmost_j = cls.leftmost_j = cls.downmost_j = cls.upmost_j = j
        elif extremo == \
                4:  # leftmost
            # Achar o alien mais à esquerda requer achar a coluna de menor índice.
            menor_j = 10000  # portanto, inicializamos com um valor alto, para garantir que será trocado.
            '''preferencialmente, esse alien não estará embaixo, que estatisticamente tem mais chances de ser atingido,
            forçando uma troca desnecessária. Portanto, caso empatem no J (coluna), escolheremos o de i menor.'''
            menor_i = 10000  # portanto, inicializamos com um valor alto, para garantir que será trocado.
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
        for i, linha in enumerate(cls.matriz):
            if linha:
                if cls.leftmost_i >= len(cls.matriz) or cls.leftmost_j >= len(cls.matriz[i]):
                    print(linha)
                primeiro_alien = cls.matriz[cls.leftmost_i][cls.leftmost_j]
                ultimo_alien = cls.matriz[cls.rightmost_i][cls.rightmost_j]
                if primeiro_alien.x < 0 or ultimo_alien.x + ultimo_alien.width >= width:
                    cls.velx *= -1
                    cls.vely = primeiro_alien.height / 2
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
                        if tiro.collided(alien) and alien.get_curr_frame() != 2:
                            qtdhits += 1
                            if alien is cls.boss and cls.vidas_boss > 0:
                                cls.vidas_boss -= 1
                                if cls.vidas_boss == 0:
                                    alien.set_curr_frame(2)
                            else:
                                alien.set_curr_frame(2)
                            lista_tiro.pop(t)
                            break
        return qtdhits


class Player(Sprite):
    caminho_sprite = f'{getcwd()}\\Player.png'
    caminho_sprite_vidas = f'{getcwd()}\\vidas.png'

    def __init__(self, dificuldade, janela, x=0, y=0, vidas=3):
        super().__init__(self.caminho_sprite, 2)
        self.janela = janela
        self.x = x
        self.y = y
        self.vidas_sprite = Sprite(self.caminho_sprite_vidas, 4)
        self.vidas_sprite.set_position(janela.width - self.vidas_sprite.width * 1.5,
                                       janela.height - self.height * 2)
        self.vidas = vidas
        self.invulnerability_timer = 0
        if dificuldade == 'Fácil':
            self.velX = 600
            self.tiros_delay = 0.4
        elif dificuldade == 'Médio':
            self.velX = 450
            self.tiros_delay = 0.6
        else:
            self.velX = 300
            self.tiros_delay = 0.8

    def checar_hit(self, lista_tiro):
        for i, tiro in enumerate(lista_tiro):
            if tiro.collided(self):
                lista_tiro.pop(i)
                if self.invulnerability_timer > 2:
                    self.vidas -= 1
                    self.x = self.janela.width / 2 - self.width / 2
                    self.invulnerability_timer = 0

    def update_invulnerabilidade(self):
        self.invulnerability_timer += self.janela.delta_time()
        timer_times10 = self.invulnerability_timer * 10
        if self.invulnerability_timer <= 2 and int(timer_times10) % 2 == 0:
            self.set_curr_frame(1)
        else:
            self.set_curr_frame(0)

    def drawvidas(self):
        self.vidas_sprite.set_curr_frame(self.vidas)
        self.vidas_sprite.draw()


class Tiro:
    caminho_sprite = f'{getcwd()}\\tiro.png'
    tiros_player = []
    tiros_enemy = []
    velY_tiro_player = 600
    velY_tiro_enemy = -250
    timer_frame = 0

    def __init__(self, direction: int, mid_x, shooter_y):
        self.sprite = Sprite(self.caminho_sprite, 6)
        self.sprite.x = mid_x - self.sprite.width / 2
        if direction > 0:
            self.sprite.y = shooter_y - self.sprite.height
            self.tiros_player.append(self.sprite)
        else:
            self.sprite.y = shooter_y + self.sprite.height
            self.tiros_enemy.append(self.sprite)

    @classmethod
    def clear_and_draw(cls, janela):
        cls.timer_frame += janela.delta_time()
        for i, tiro in enumerate(cls.tiros_player):
            tiro.y -= cls.velY_tiro_player * janela.delta_time()
            if tiro.y + tiro.height <= 0:
                cls.tiros_player.pop(i)
            else:
                tiro.draw()
                if cls.timer_frame >= 0.15:
                    tiro.set_curr_frame((tiro.get_curr_frame() + 1) % 6)
        for i, tiro in enumerate(cls.tiros_enemy):
            tiro.y -= cls.velY_tiro_enemy * janela.delta_time()
            if tiro.y >= janela.height:
                cls.tiros_enemy.pop(i)
            else:
                tiro.draw()
                if cls.timer_frame >= 0.15:
                    tiro.set_curr_frame((tiro.get_curr_frame() + 1) % 6)
        cls.timer_frame = 0 if cls.timer_frame >= 0.15 else cls.timer_frame

    @classmethod
    def draw(cls):
        for tiro in cls.tiros_player:
            tiro.draw()
        for tiro in cls.tiros_enemy:
            tiro.draw()
