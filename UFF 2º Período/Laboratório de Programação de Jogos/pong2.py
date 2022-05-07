from PPlay.sprite import *
from PPlay.window import *
from PPlay.gameimage import *
from random import random
# inicializando janela
janela = Window(910, 512)
fundo = GameImage('espaco.jpg')
teclado = Window.get_keyboard()
# passo do jogo (variaveis que servem para aumentar todas as velocidades de uma vez caso desejado)
playerspeedpace = 150
ballspeedpace = 75
# inicializando bola
bola = Sprite('bola.jpg')
bola.set_position(janela.width / 2 - bola.width / 2, janela.height / 2 - bola.height / 2)
x_orig_bola = janela.width / 2 - bola.width / 2
y_orig_bola = janela.height / 2 - bola.height / 2
velX = (3 if random() < 0.5 else -3)
velY = (3 if random() < 0.5 else -3)
# Inicializando jogadores
# Jogador 1
jogador1 = Sprite('barra.jpg')
pontosjogador1 = 0
jogador1.set_position(25, janela.height / 2 - jogador1.height/2)
# Jogador 2
jogador2 = Sprite('barra.jpg')
pontosjogador2 = 0
jogador2.set_position(janela.width - 25, janela.height/2 - jogador2.height/2)

# Game Loop
while True:
    janela.update()
    pace = janela.delta_time()
    # inputs
    if jogador2.y > 0:
        if teclado.key_pressed("UP"):
            jogador2.y -= 4 * pace * playerspeedpace
    if jogador2.y < janela.height - jogador2.height:
        if teclado.key_pressed("DOWN"):
            jogador2.y += 4 * pace * playerspeedpace
    if jogador1.y > 0:
        if teclado.key_pressed("w"):
            jogador1.y -= 4 * pace * playerspeedpace
    if jogador1.y < janela.height - jogador2.height:
        if teclado.key_pressed("s"):
            jogador1.y += 4 * pace * playerspeedpace
    # updates
    bola.x += velX * pace * ballspeedpace
    bola.y += velY * pace * ballspeedpace
    if bola.x <= 0:  # Clisão parede esquerda
        bola.set_position(x_orig_bola, y_orig_bola)
        pontosjogador2 += 1
    if bola.x + bola.width >= janela.width:  # Colisão parede direita
        bola.set_position(x_orig_bola, y_orig_bola)
        pontosjogador1 += 1
    if bola.y <= 0 or bola.y + bola.height >= janela.height:  # Colisão com teto ou chão
        velY *= -1
        bola.x += velY * pace * ballspeedpace  # desfaz o movimento que causou a colisão
    if bola.collided(jogador1):
        velX *= -1
        bola.x = jogador1.x + bola.width # desfaz a colisão teleportando a bola
    if bola.collided(jogador2):
        velX *= -1
        bola.x = jogador2.x - bola.width  # desfaz a colisão
    # desenhar
    fundo.draw()
    jogador1.draw()
    jogador2.draw()
    bola.draw()
