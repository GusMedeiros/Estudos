from random import randint, random
from PPlay.window import *
from PPlay.gameimage import *
from PPlay.sprite import *


def checar_pause(jan, tecl):
    return tecl.key_pressed('esc')


def pause(jan, tecl, delay_t):
    animacao = Sprite('bola.jpg', 2)
    animacao.set_total_duration(5)
    animacao.y = jan.height/2
    animacao.x = jan.width/2
    soltou = 0
    while True:
        esc = tecl.key_pressed('esc')
        if not esc:
            soltou = True
        if esc and soltou:
            return None
        jan.draw_text("Pausado!", jan.width/2 - jan.width/10, jan.height/2 - jan.height/20, int(jan.height/10), (255, 255, 255))
        animacao.draw()
        jan.update()
        animacao.update()


def marcarponto(jogador):
    jogador.pontos += 1
    return None


def resetar(objeto):
    objeto.x = objeto.x_orig
    objeto.y = objeto.y_orig
    return None


def kickstart(objeto):
    sinal_aleatorio = 1 if random() < 0.5 else 1
    objeto.velX = 3 * (delay/16) * sinal_aleatorio
    sinal_aleatorio = 1 if random() < 0.5 else 1
    objeto.velY = randint(1, 10) * 3 * (delay/16) / 10 * sinal_aleatorio
    return None


def colisao(ball, jogador):
    if ball.x <= jogador.x + jogador.width and ball.x + ball.width >= jogador.x:
        if ball.y <= jogador.y + jogador.height and ball.y + ball.height >= jogador.y:
            return True
    return False


# inicializações
bloqueia_esc = False
# carregando imagens

janela = Window(910, 512)
delay = 16
teclado = janela.get_keyboard()
fundo = GameImage("espaco.jpg")
jogador1 = Sprite("barra.jpg", 1)
jogador2 = Sprite("barra.jpg", 1)
bola = Sprite("bola.jpg", 1)

# setando origem da bola no centro
bola.x_orig = janela.width/2 - bola.width/2
bola.y_orig = janela.height/2 - bola.height/2

# dando velocidade à bola
bola.velX = float
bola.velY = float
kickstart(bola)
multY = 1
# setando origem do jogador 1
jogador1.x_orig = 70
jogador1.y_orig = janela.height/2 - jogador1.height/2

# setando origem do jogador 2
jogador2.x_orig = janela.width - jogador2.width - 70
jogador2.y_orig = janela.height/2 - jogador2.height/2

# setando placar
jogador1.pontos = jogador2.pontos = 0
# resetando posições dos jogadores e bola
resetar(jogador1)
resetar(jogador2)
resetar(bola)
# Game Loop
while True:
    if checar_pause(janela, teclado) and not bloqueia_esc:
        bloqueia_esc = True
        pause(janela, teclado, delay)
    bloqueia_esc = False if not teclado.key_pressed('esc') else True

    # entrada de dados
    baixo = teclado.key_pressed('down')
    cima = teclado.key_pressed('up')
    baixoS = teclado.key_pressed('s')
    cimaW = teclado.key_pressed('w')
    # atualização
    janela.delay(delay)
    janela.update()
    # movendo jogador 1 (esquerdo)
    jogador1.y -= 12 * delay / 16 if cimaW and 0 < jogador1.y else 0
    jogador1.y += 12 * delay / 16 if baixoS and jogador1.height + jogador1.y < janela.height else 0
    # movendo jogador 2 (direito)
    jogador2.y -= 12 * delay / 16 if cima and 0 < jogador2.y else 0
    jogador2.y += 12 * delay / 16 if baixo and jogador1.height + jogador2.y < janela.height else 0

    if bola.x >= janela.width - bola.width:  # checar colisão da bola com lado direito
        marcarponto(jogador1)
        print(jogador1.pontos, jogador2.pontos)
        resetar(bola)
        kickstart(bola)
    elif bola.x <= 0:  # checar colisão da bola com lado esquerdo
        marcarponto(jogador2)
        print(jogador1.pontos, jogador2.pontos)
        resetar(bola)
        kickstart(bola)
    if bola.y >= janela.height - bola.height:  # checar colisão da bola com lado de cima
        bola.velY *= -1
    elif bola.y <= 0:  # checar colisão da bola com lado de baixo
        bola.velY *= -1
    if colisao(bola, jogador1) and (bola.velX < 0) or colisao(bola, jogador2) and (bola.velX > 0):  # se houver colisão
        bola.velX *= -1
        if abs(bola.velY) < 14:  # limitando um pouco a velocidade da bola
            bola.velY += randint(0, 2) * 3 / 10 * multY
        if 0 < bola.velX < 14:  # se a bola rebateu pra direita
            bola.velX += 1.2
            multY += 0.5
        else:  # se a bola rebateu pra esquerdo
            if 0 > bola.velX > -14:
                bola.velX -= 1.2
                multY += 0.5
    # movendo bola
    bola.x += bola.velX
    bola.y += bola.velY
    # desenho
    fundo.draw()
    janela.draw_text(f"{jogador1.pontos}", janela.width/6, janela.height/10, int(janela.height/8), (255, 255, 255))
    janela.draw_text(f"{jogador2.pontos}", janela.width * 5 / 6, janela.height/10, int(janela.height/8), (255, 255, 255))
    jogador1.draw()
    jogador2.draw()
    bola.draw()
