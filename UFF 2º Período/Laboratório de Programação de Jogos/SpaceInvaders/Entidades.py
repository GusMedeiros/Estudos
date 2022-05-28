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
