from PPlay.sprite import *
from PPlay.window import *
from PPlay.gameimage import *
from random import random


def checar_pause(jan, tecl):
    return tecl.key_pressed('esc')


def pause(jan, tecl, delay_t):
    soltou = 0
    while True:
        esc = tecl.key_pressed('esc')
        if not esc:
            soltou = True
        if esc and soltou:
            return None
        jan.draw_text("Pausado!", jan.width/2 - jan.width/10, jan.height/2 - jan.height/20, int(jan.height/10), (255, 255, 255))
        jan.update()


# inicializando janela
janela = Window(910, 512)
fundo = GameImage('../espaco.jpg')
teclado = Window.get_keyboard()
# passo do jogo (variaveis que servem para aumentar todas as velocidades de uma vez caso desejado)
playerspeedpace = 150
ballspeedpace = 75
# inicializando bola
bola = Sprite('../bola.jpg')
x_orig_bola = janela.width / 2 - bola.width / 2
y_orig_bola = janela.height / 2 - bola.height / 2
bola.set_position(x_orig_bola, y_orig_bola)
velX = (3 if random() < 0.5 else -3)
velY = (3 if random() < 0.5 else -3)
# Inicializando jogadores
jogadorsegurando = False
# Jogador 1 (BOT)
jogador1 = Sprite('../barra.jpg')
pontosjogador1 = 0
jogador1.set_position(jogador1.width, janela.height / 2 - jogador1.height/2)
botspeedpace = 180
# Jogador 2
jogador2 = Sprite('../barra.jpg')
pontosjogador2 = 0
jogador2.set_position(janela.width - 2 * jogador2.width, janela.height/2 - jogador2.height/2)
# Mantendo o jogo despausado
bloqueia_esc = False
# Game Loop
while True:
    if checar_pause(janela, teclado) and not bloqueia_esc:
        bloqueia_esc = True
        pause(janela, teclado, 16)
    bloqueia_esc = False if not teclado.key_pressed('esc') else True
    janela.update()
    pace = janela.delta_time()
    # inputs do player
    if jogador2.y > 0:
        if bola.y + bola.height/2 < jogador2.y + jogador2.height/2:
            jogador2.y -= 4 * pace * playerspeedpace
            if jogadorsegurando and bola.x > janela.width/2:
                bola.y -= 4 * pace * playerspeedpace
    if jogador2.y < janela.height - jogador2.height:
        if bola.y - bola.height/2 > jogador2.y + jogador2.height/2:
            jogador2.y += 4 * pace * playerspeedpace
            if jogadorsegurando and bola.x > janela.width/2:
                bola.y += 4 * pace * playerspeedpace
    # inputs do bot
    # BOT W:
    if jogador1.y > 0:  # limite superior
        if bola.y + bola.height / 2 < jogador1.y + jogador1.height/2 and bola.x + bola.width/2 < janela.width*5/6:
            jogador1.y -= 1 * pace * botspeedpace
            if jogadorsegurando and bola.x < janela.width/2:
                bola.y -= 1 * pace * botspeedpace
    # BOT S:
    if jogador1.y < janela.height - jogador2.height:  # limite inferior
        if bola.y+bola.height/2 > jogador1.y+jogador1.height/2 and bola.x + bola.width/2 < janela.width*5/6:
            jogador1.y += 1 * pace * botspeedpace
            if jogadorsegurando and bola.x < janela.width/2:
                bola.y += 1 * pace * botspeedpace
    # chute:
    if jogadorsegurando:
        if bola.x > janela.width / 2:  # se a bola estiver pro lado direito
            velX = -3
            bola.x = jogador2.x - bola.width
        else:  # se a bola estiver pro lado esquerdo ( com o bot )
            velX = 3
            bola.x = jogador1.x + jogador1.width
        velY = (3 if random() < 0.5 else -3)
        jogadorsegurando = False
    # updates
    bola.x += velX * pace * ballspeedpace
    bola.y += velY * pace * ballspeedpace
    if bola.x + bola.width <= 0:  # Colisão parede esquerda
        bola.set_position(jogador2.x - jogador2.width/2 - bola.width/2, jogador2.y + jogador2.height / 2 - bola.height/2)
        jogadorsegurando = True
        pontosjogador2 += 1
        velX = 0
        velY = 0
    if bola.x >= janela.width:  # Colisão parede direita
        bola.set_position(jogador1.x - jogador1.width/2 + bola.width/2, jogador1.y + jogador1.height/2 - bola.height/2)
        jogadorsegurando = True
        pontosjogador1 += 1
        velX = 0
        velY = 0
    if bola.y <= 0 or bola.y + bola.height >= janela.height:  # Colisão com teto ou chão
        velY *= -1
        bola.y += velY * pace * ballspeedpace  # desfaz o movimento que causou a colisão
    if bola.collided(jogador1) and not jogadorsegurando:  # colisao com jogador 1
        if bola.x - velX * pace * ballspeedpace < jogador1.x + jogador1.width:  # se bateu nas pontas da barra
            velY *= -1
            bola.y = jogador1.y - bola.height if bola.y < jogador1.y + jogador1.height / 2 else jogador1.y + jogador1.height
            # bola.y += velY * pace * ballspeedpace
        else:
            velX *= -1
            bola.x += velX * pace * ballspeedpace
    if bola.collided(jogador2) and not jogadorsegurando:  # colisao com jogador2
        if bola.x + bola.width - velX * pace * ballspeedpace > jogador2.x:  # se bateu nas pontas da barra
            velY *= -1
            bola.y = jogador2.y - bola.height if bola.y < jogador2.y + jogador2.height / 2 else jogador2.y + jogador2.height
            # bola.y += velY * pace * ballspeedpace
        else:
            velX *= -1
            bola.x += velX * pace * ballspeedpace

    # desenhar
    fundo.draw()
    janela.draw_text(f"{pontosjogador1}", janela.width / 6, janela.height / 10, int(janela.height / 8),
                     (255, 255, 255))
    janela.draw_text(f"{pontosjogador2}", janela.width * 5 / 6, janela.height / 10, int(janela.height / 8),
                     (255, 255, 255))
    jogador1.draw()
    jogador2.draw()
    bola.draw()
