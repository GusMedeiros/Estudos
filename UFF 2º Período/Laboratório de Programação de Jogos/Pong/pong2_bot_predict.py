from PPlay.sprite import *
from PPlay.window import *
from PPlay.gameimage import *
from random import random, randint

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
relogio = 0
relogiomax = 0
# passo do jogo (variaveis que servem para aumentar todas as velocidades de uma vez caso desejado)
playerspeedpace = 150
ballspeedpace = 75
predictmultiplier = 2
botspeedpace = 180
# inicializando bola
bola = Sprite('../bola.jpg')
x_orig_bola = janela.width / 2 - bola.width / 2
y_orig_bola = janela.height / 2 - bola.height / 2
bola.set_position(x_orig_bola, y_orig_bola)
velX = (3 if random() < 0.5 else -3)
velY = (3 if random() < 0.5 else -3)
# inicializando bola invisível de previsão
bola_previsao = Sprite('../bola.jpg')
bola_previsao.set_position(bola.x, bola.y)
velX_previsao = velX
velY_previsao = velY
previsaoligada = velX < 0
previsaoterminada = False
comecarprevisao = False
# Inicializando jogadores
jogadorsegurando = False
# Jogador 1
jogador1 = Sprite('../barra.jpg')
pontosjogador1 = 0
jogador1.set_position(jogador1.width, janela.height / 2 - jogador1.height/2)
irpracima = random() > 0.5
# Jogador 2
jogador2 = Sprite('../barra.jpg')
pontosjogador2 = 0
jogador2.set_position(janela.width - 2 * jogador2.width , janela.height/2 - jogador2.height/2)
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
    # inputs
    if jogador2.y > 0:
        if teclado.key_pressed("UP"):
            jogador2.y -= 4 * pace * playerspeedpace
            if jogadorsegurando and bola.x > janela.width/2:
                bola.y -= 4 * pace * playerspeedpace
    if jogador2.y < janela.height - jogador2.height:
        if teclado.key_pressed("DOWN"):
            jogador2.y += 4 * pace * playerspeedpace
            if jogadorsegurando and bola.x > janela.width/2:
                bola.y += 4 * pace * playerspeedpace
    """if jogador1.y > 0:
        if teclado.key_pressed("w"):
            jogador1.y -= 4 * pace * playerspeedpace
            if jogadorsegurando and bola.x < janela.width/2:
                bola.y -= 4 * pace * playerspeedpace
    if jogador1.y < janela.height - jogador2.height:
        if teclado.key_pressed("s"):
            jogador1.y += 4 * pace * playerspeedpace
            if jogadorsegurando and bola.x < janela.width/2:
                bola.y += 4 * pace * playerspeedpace """
    # inputs do bot
    if not previsaoterminada:
        if jogador1.y + jogador1.height/2 <= janela.height * 2/6:
            irpracima = False
        if jogador1.y + jogador1.height/2 >= janela.height * 4/6:
            irpracima = True
        if irpracima:
            jogador1.y -= 1.6 * pace * botspeedpace
            if jogadorsegurando and bola.x < janela.width/2:
                bola.y -= 1.6 * pace * botspeedpace
        else:
            jogador1.y += 1.6 * pace * botspeedpace
            if jogadorsegurando and bola.x < janela.width/2:
                bola.y += 1.6 * pace * botspeedpace
    else:
        # BOT W:
        if jogador1.y > 0:  # limite superior
            if bola_previsao.y + bola_previsao.height / 2 < jogador1.y + jogador1.height / 2 and bola_previsao.x + bola_previsao.width / 2 < janela.width * 5 / 6:
                jogador1.y -= 1 * pace * botspeedpace
                if jogadorsegurando and bola_previsao.x < janela.width / 2:
                    bola_previsao.y -= 1 * pace * botspeedpace
        # BOT S:
        if jogador1.y < janela.height - jogador2.height:  # limite inferior
            if bola_previsao.y + bola_previsao.height / 2 > jogador1.y + jogador1.height / 2 and bola_previsao.x + bola_previsao.width / 2 < janela.width * 5 / 6:
                jogador1.y += 1 * pace * botspeedpace
                if jogadorsegurando and bola_previsao.x < janela.width / 2:
                    bola_previsao.y += 1 * pace * botspeedpace

    if (teclado.key_pressed("space") or bola.x < janela.width / 2) and jogadorsegurando:
        bola_previsao.set_position(bola.x, bola.y)
        if bola.x > janela.width / 2:  # se a bola estiver pro lado direito
            velX = -3
            bola.x = jogador2.x - bola.width
            comecarprevisao = True
            jogadorsegurando = False
            velY = (3 if random() < 0.5 else -3)
        else:  # se a bola estiver pro lado esquerdo ( com o bot )
            if relogio >= relogiomax:
                velX = 3
                bola.x = jogador1.x + jogador1.width
                comecarprevisao = False
                jogadorsegurando = False
                velY = (3 if random() < 0.5 else -3)
                relogio = 0

            else:
                relogio += pace



    # updates
    bola.x += velX * pace * ballspeedpace
    bola.y += velY * pace * ballspeedpace
    bola_previsao.x += velX_previsao * pace * ballspeedpace * predictmultiplier
    bola_previsao.y += velY_previsao * pace * ballspeedpace * predictmultiplier
    if bola.x + bola.width <= 0:  # Colisão parede esquerda
        # bola real
        bola.set_position(jogador2.x - jogador2.width/2 - bola.width/2, jogador2.y + jogador2.height / 2 - bola.height/2)
        jogadorsegurando = True
        pontosjogador2 += 1
        velX = 0
        velY = 0
        # bola previsao
        bola_previsao.set_position(bola.x, bola.y)
        velX_previsao = velX
        velY_previsao = velY
    if bola.x >= janela.width:  # Colisão parede direita
        bola.set_position(jogador1.x - jogador1.width/2 + bola.width/2, jogador1.y + jogador1.height/2 - bola.height/2)
        jogadorsegurando = True
        pontosjogador1 += 1
        velX = 0
        velY = 0
        # previsao
        bola_previsao.set_position(bola.x, bola.y)
        velX_previsao = velX
        velY_previsao = velY
        previsaoterminada = False
        relogiomax = randint(0, 16)/10
    # Colisão da bola real com teto ou chão
    if bola.y <= 0 or bola.y + bola.height >= janela.height:
        velY *= -1
        bola.y += velY * pace * ballspeedpace  # desfaz o movimento que causou a colisão
    if bola.collided(jogador1) and not jogadorsegurando:  # colisao com jogador 1
        if bola.x - velX * pace * ballspeedpace < jogador1.x + jogador1.width:  # se bateu nas pontas da barra
            velY *= -1
            bola.y = jogador1.y - bola.height if bola.y < jogador1.y + jogador1.height / 2 else jogador1.y + jogador1.height
            velY *= 1.1
            # bola.y += velY * pace * ballspeedpace
        else:
            velX *= -1
            bola.x += velX * pace * ballspeedpace
            velY *= 1.1
    if bola.collided(jogador2) and not jogadorsegurando:  # colisao com jogador2
        if bola.x + bola.width - velX * pace * ballspeedpace > jogador2.x:  # se bateu nas pontas da barra
            velY *= -1
            bola.y = jogador2.y - bola.height if bola.y < jogador2.y + jogador2.height / 2 else jogador2.y + jogador2.height
            velY *= 1.1
            # bola.y += velY * pace * ballspeedpace
        else:
            velX *= -1
            bola.x += velX * pace * ballspeedpace
            velY *= 1.1
    # previsão do bot
    # colisão da bola previsão com teto ou chão
    if bola_previsao.y <= 0 or bola_previsao.y + bola_previsao.height >= janela.height:
        velY_previsao *= -1
        bola_previsao.y += velY_previsao * pace * ballspeedpace * predictmultiplier



    if bola_previsao.x <= jogador1.x + jogador1.width and not jogadorsegurando:  # se BP passar do jogador1
        previsaoterminada = True
    if velX > 0:  # se BP estiver indo pra direita
        previsaoligada = False
        previsaoterminada = False
    if previsaoligada == False and velX < 0:  # se bola real estiver indo pra esquerda e previsao estiver desligada
        comecarprevisao = True  # ligar previsao
        previsaoligada = True
        previsaoterminada = False
    if comecarprevisao:  # fazer bola previsao andar
        bola_previsao.set_position(bola.x, bola.y)
        velX_previsao = (1 + randint(0, 3)/100) * velX
        velY_previsao = (1 + randint(0, 4)/100) * velY
        comecarprevisao = False
        previsaoterminada = False
    if jogadorsegurando:
        bola_previsao.set_position(bola.x, bola.y)
        previsaoterminada = False
    if previsaoterminada and not jogadorsegurando:
        velX_previsao = 0
        velY_previsao = 0


    # desenhar
    fundo.draw()
    janela.draw_text(f"{pontosjogador1}", janela.width / 6, janela.height / 10, int(janela.height / 8),
                     (255, 255, 255))
    janela.draw_text(f"{pontosjogador2}", janela.width * 5 / 6, janela.height / 10, int(janela.height / 8),
                     (255, 255, 255))
    jogador1.draw()
    jogador2.draw()
    bola.draw()
    bola_previsao.draw()