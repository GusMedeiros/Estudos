'''from random import randint
from PPlay.window import *
from PPlay.gameimage import *
from PPlay.sprite import *'''
def marcarponto(jogador):
    jogador.pontos += 1

    return None

def resetar(gameobject):
    gameobject.x = gameobject.x_orig
    gameobject.y = gameobject.y_orig
    return None


def kickstart(gameobject):
    sinal_aleatorio = randint(0, 1)
    if sinal_aleatorio == 0:
        sinal_aleatorio = -1
    else:
        sinal_aleatorio = 1
    gameobject.velX = 1 * sinal_aleatorio
    sinal_aleatorio = randint(0, 1)
    if sinal_aleatorio == 0:
        sinal_aleatorio = -1
    else:
        sinal_aleatorio = 1
    # gameobject.velY = randint(3, 10)/10 * sinal_aleatorio
    gameobject.velY = 0
    return None


def colisao(ball, jogador):
    if ball.x <= jogador.x + jogador.width and ball.x + ball.width >= jogador.x:
        if ball.y <= jogador.y + jogador.height and ball.y + ball.height >= jogador.y:
            return True
    return False


# inicializações
# carregando imagens

janela = Window(800, 800)
teclado = janela.get_keyboard()
fundo = GameImage("nebula.jpg")
jogador1 = Sprite("barra.jpg", 1)
jogador2 = Sprite("barra.jpg", 1)
bola = Sprite("bola.jpg", 1)

# setando origem da bola no centro
bola.x_orig = janela.width/2 - bola.width/2
bola.y_orig = janela.height /2 - bola.height/2

# dando velocidade à bola
bola.velX = float
bola.velY = float
kickstart(bola)
# setando origem do jogador 1
jogador1.x_orig = 70
jogador1.y_orig = janela.height/2 - jogador1.height/2

# setando origem do jogador 2
jogador2.x_orig = janela.width - jogador2.width - 70
jogador2.y_orig = janela.height/2 - jogador2.height/2

# setando placar
jogador1.pontos = jogador2.pontos = 0

resetar(jogador1)
resetar(jogador2)
resetar(bola)
# Game Loop
while True:
    # entrada de dados
    # atualização
    janela.update()
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
        while True:
            pass
    '''    if bola.velX > 0:  # se a bola rebateu pra direita
            bola.velX += 0.4
        else:  # se a bola rebateu pra esquerda
            bola.velX -= 0.4
'''
    if teclado.key_pressed('down'):
        jogador2.y += 2
    if teclado.key_pressed('up'):
        jogador2.y -= 2

    if teclado.key_pressed("s"):
        jogador1.y += 2
    if teclado.key_pressed('w'):
        jogador1.y -= 2


    bola.x += bola.velX
    bola.y += bola.velY
    # desenho
    fundo.draw()
    jogador1.draw()
    jogador2.draw()
    bola.draw()