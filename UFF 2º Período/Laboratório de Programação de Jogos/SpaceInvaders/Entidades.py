from PPlay.sprite import Sprite


class Enemy(Sprite):
    matriz = []
    caminho_sprite = 'alien.png'
    tempo_acumulado_frames = 0
    tempo_acumulado_mover = 0
    colisao = False
    velx = 100
    vely = 0

    def __init__(self, dificuldade, x=0, y=0):
        super().__init__(self.caminho_sprite, 3)

        self.x = x
        self.y = y

    @classmethod
    def reset(cls):
        cls.matriz = []
        cls.caminho_sprite = 'alien.png'
        cls.tempo_acumulado_frames = 0
        cls.tempo_acumulado_mover = 0
        cls.colisao = False
        cls.velx = 100
        cls.vely = 0

    @classmethod
    def spawn(cls, dificuldade, colunas, linhas):
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
        for linha in cls.matriz:
            for j, alien in enumerate(linha):
                alien.x += cls.velx * delta_time
                alien.y += cls.vely
                alien.draw()
                if cls.tempo_acumulado_frames > 0.5:
                    if alien.get_curr_frame() != 2:
                        alien.set_curr_frame((alien.get_curr_frame() + 1) % 2)
                    else:
                        linha.pop(j)
        if cls.tempo_acumulado_frames > 0.5:
            cls.tempo_acumulado_frames = 0

    @classmethod
    def desenhar(cls):
        for linha in cls.matriz:
            for alien in linha:
                alien.draw()

    @classmethod
    def tem_alien(cls):
        for linha in cls.matriz:
            if linha:
                return True
        return False

    @classmethod
    def colisao_parede(cls, width, delta_time):
        for linha in cls.matriz:
            if linha:
                primeiro_alien = linha[0]
                ultimo_alien = linha[-1]
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
                alien.x += cls.velx * delta_time
                if moverY:
                    alien.y += cls.vely

    @classmethod
    def checar_hit(cls, lista_tiro):
        for t, tiro in enumerate(lista_tiro):
            for i, linha in enumerate(cls.matriz):
                if linha:
                    if tiro.y <= linha[0].y + linha[0].height and tiro.y + tiro.height >= linha[0].y:
                        for j, alien in enumerate(linha):
                            if lista_tiro and linha[j]:
                                if tiro.collided(alien) and alien.get_curr_frame() != 2:
                                    lista_tiro.pop(t)
                                    alien.set_curr_frame(2)


class Player(Sprite):
    caminho_sprite = 'Player.png'

    def __init__(self, dificuldade, x=0, y=0):
        super().__init__(self.caminho_sprite)
        self.x = x
        self.y = y
        if dificuldade == 'Fácil':
            self.velX = 600
            self.tiros_delay = 0.15
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
    def update_and_draw(cls, janela):
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
