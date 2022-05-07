from PPlay.sprite import *
from PPlay.window import *
from PPlay.gameimage import *
from random import random
janela = Window(600, 600)
fundo = GameImage('white800x600.png')
fundo.draw()
dvd = Sprite('dvd.png')
dvd.set_position(janela.width/2 - dvd.width/2, janela.height/2 - dvd.height/2)
velX = 3 if random() < 0.5 else -3
velY = 3 if random() < 0.5 else -3
while True:
    janela.update()
    fundo.draw()
    dvd.draw()
    dvd.x += velX
    dvd.y += velY
    if dvd.x <= 0 or dvd.x + dvd.width >= janela.width:
        velX *= -1
    if dvd.y <= 0 or dvd.y + dvd.height >= janela.height:
        velY *= -1
    janela.delay(10)

