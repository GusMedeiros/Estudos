from PPlay.window import Window
from PPlay.sprite import Sprite
from PPlay.gameimage import GameImage
from PPlay.animation import Animation

def menuinicial():
    janela = Window(1366, 768)
    fundo = GameImage('espaco.jpg')
    teclado = janela.get_keyboard()
    # mouse
    mouse = janela.get_mouse()
    mousesprite = Sprite('mouse.png')
    mousesprite.set_position(janela.width/2 - mousesprite.width/2, janela.height/2 - mousesprite.height/2)
    mousehitbox = Sprite('1x1.png')
    mouse.hide()
    mb1click2 = False
    # jogar
    botaojogar = Sprite('Botaojogar.png')
    # ranking
    botaoranking = Sprite('Botaoranking.png')
    # sair
    botaosair = Sprite('Botaosair.png')
    # dificuldade
    '''botaodificuldade = Sprite('Botaodificuldade.png')'''
    botaodificuldade = Animation('teste.bmp', 8)
    dificuldadeslista = ["Fácil", "Médio", "Difícil"]
    dificuldadeindice = 0
    dificuldade = dificuldadeslista[0]
    tamanhofonte = 28

    # posicoes dos botões
    botaojogar.set_position(janela.width/2 - botaojogar.width/2, janela.height * 1/10)
    botaodificuldade.set_position(botaojogar.x, botaojogar.y + botaojogar.height * 1.3)
    botaoranking.set_position(botaojogar.x, botaodificuldade.y + botaojogar.height * 1.3)
    botaosair.set_position(botaojogar.x, botaoranking.y + botaojogar.height * 1.3)
    #
    teste = Sprite("teste.py", 24)
    teste.set_position(janela.width/2, janela.height/2)
    while True:
        posicao = mouse.get_position()
        # inputs do mouse
        mousesprite.set_position(posicao[0], posicao[1])
        mousehitbox.set_position(posicao[0], posicao[1])
        mb1click = mouse.is_button_pressed(1)
        # checar botao apertado
        if mousehitbox.collided_perfect(botaojogar):
            if not mb1click and mb1click2:
                # animacaojogar()
                return dificuldade
        if mousehitbox.collided_perfect(botaodificuldade):
            botaodificuldade.set_curr_frame(5)
            if not mb1click and mb1click2:
                dificuldadeindice += 1
                dificuldade = dificuldadeslista[dificuldadeindice % 3]
        if mousehitbox.collided_perfect(botaoranking):
            if not mb1click and mb1click2:
                pass
                # ranking()
        if mousehitbox.collided_perfect(botaosair):
            if not mb1click and mb1click2:
                # animacaosair()
                return "Fechar"
        mb1click2 = mouse.is_button_pressed(1)
        # updates
        janela.update()
        # draws
        fundo.draw()
        botaojogar.draw()
        botaodificuldade.draw()
        janela.draw_text(dificuldade, botaodificuldade.x + 20, botaodificuldade.y + botaodificuldade.height*0.74, tamanhofonte)
        botaoranking.draw()
        botaosair.draw()
        teste.draw()
        # mouse sempre por ultimo:
        mousesprite.draw()
        mousehitbox.draw()


menuinicial()
