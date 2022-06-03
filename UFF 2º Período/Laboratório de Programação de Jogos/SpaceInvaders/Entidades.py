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
        super().__init__(self.caminho_sprite, 2)

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
    def desenhar_e_mover(cls, delta_time):
        cls.tempo_acumulado_frames += delta_time
        for linha in cls.matriz:
            for alien in linha:
                alien.x += cls.velx * delta_time
                alien.y += cls.vely
                alien.draw()
                if cls.tempo_acumulado_frames > 0.5:
                    alien.set_curr_frame((alien.get_curr_frame() + 1) % 2)
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
                            if lista_tiro:
                                if tiro.collided(alien):
                                    linha.pop(j)
                                    lista_tiro.pop(t)


class Player:
    def __init__(self, sprite, dificuldade, x=0, y=0):
        self.sprite = sprite
        self._x = x
        self._y = y
        self.width = sprite.width
        self.height = sprite.height
        if dificuldade == 'Fácil':
            self.velX = 600
            self.tiros_delay = 0.15
        elif dificuldade == 'Médio':
            self.velX = 450
            self.tiros_delay = 0.25
        else:
            self.velX = 300
            self.tiros_delay = 0.5

    @property
    def x(self):
        return self._x

    @x.setter
    def x(self, x):
        self._x = x
        self.sprite.x = x

    @property
    def y(self):
        return self._y

    def set_position(self, x, y):
        self._x = x
        self._y = y
        self.sprite.set_position(x, y)

    def draw(self):
        self.sprite.draw()


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
