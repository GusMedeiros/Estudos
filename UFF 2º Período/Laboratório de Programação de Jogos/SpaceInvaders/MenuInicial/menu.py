from PPlay.sprite import Sprite
from PPlay.gameimage import GameImage
from ranking import Ranking

def menuinicial(janela, mouse, teclado):
    fundo = GameImage('espaco.jpg')
    ranking = Ranking(janela)
    # mouse
    mouse = janela.get_mouse()
    mousesprite = Sprite('mouse.png')
    mousesprite.set_position(janela.width / 2 - mousesprite.width / 2, janela.height / 2 - mousesprite.height / 2)
    mousehitbox = Sprite('1x1.png')
    mouse.hide()
    mb1click2 = False
    # jogar
    botaojogar = Sprite('Botaojogar.png', 2)
    # ranking
    botaoranking = Sprite('Botaoranking.png', 2)
    # sair
    botaosair = Sprite('Botaosair.png', 2)
    # dificuldade
    botaodificuldade = Sprite('Botaodificuldade.png', 2)
    dificuldadeslista = ["Fácil", "Médio", "Difícil"]
    dificuldadeindice = 0
    dificuldade = dificuldadeslista[0]
    tamanhofonte = 28

    # posicoes dos botões
    botaojogar.set_position(janela.width * 0.825 - botaojogar.width / 2, janela.height * 1 / 10)
    botaodificuldade.set_position(botaojogar.x, botaojogar.y + botaojogar.height * 1.3)
    botaoranking.set_position(botaojogar.x, botaodificuldade.y + botaojogar.height * 1.3)
    botaosair.set_position(botaojogar.x, botaoranking.y + botaojogar.height * 1.3)
    #
    while True:
        posicao = mouse.get_position()
        # inputs do mouse
        mousesprite.set_position(posicao[0], posicao[1])
        mousehitbox.set_position(posicao[0], posicao[1])
        mb1click = mouse.is_button_pressed(1)
        # checar botao apertado
        if True:  # if redundante proposital, para que dê pra colapsar todos os ifs abaixo de uma vez no pycharm:
            # botao jogar
            if mousehitbox.collided_perfect(botaojogar):
                botaojogar.set_curr_frame(1)
                if not mb1click and mb1click2:
                    # animacaojogar()
                    return dificuldade
            else:
                botaojogar.set_curr_frame(0)
            # botao dificuldade
            if mousehitbox.collided_perfect(botaodificuldade):
                botaodificuldade.set_curr_frame(1)
                if not mb1click and mb1click2:
                    dificuldadeindice += 1
                    dificuldade = dificuldadeslista[dificuldadeindice % 3]
            else:
                botaodificuldade.set_curr_frame(0)
            # botao ranking
            if mousehitbox.collided_perfect(botaoranking):
                botaoranking.set_curr_frame(1)
                if not mb1click and mb1click2:
                    ranking.drawstate = not ranking.drawstate
            elif not ranking.drawstate:
                botaoranking.set_curr_frame(0)
            # botao sair
            if mousehitbox.collided_perfect(botaosair):
                botaosair.set_curr_frame(1)
                if not mb1click and mb1click2:
                    ranking.saverank()
                    # animacaosair()
                    return "Fechar"
            else:
                botaosair.set_curr_frame(0)
        mb1click2 = mouse.is_button_pressed(1)
        # updates
        janela.update()
        # draws
        fundo.draw()
        botaojogar.draw()
        botaodificuldade.draw()
        janela.draw_text(dificuldade, botaodificuldade.x + 20, botaodificuldade.y + botaodificuldade.height * 0.74,
                         tamanhofonte)
        botaoranking.draw()
        botaosair.draw()
        # ranking caso on
        if ranking.drawstate:
            ranking.animacao(1)
            print(ranking.draw())
            botaoranking.set_curr_frame(1)
        else:
            ranking.animacao(-1)
        # mouse sempre por último:
        mousesprite.draw()
        mousehitbox.draw()


def menupause(janela, mouse, teclado):
    esc_pressed_past = esc_pressed_now = False
    mb1_pressed_past = mb1_pressed_now = False
    botao_sair = Sprite('botaosair.png')
    botao_sair.set_position(janela.width/2, janela.height/2)
    mousesprite = Sprite('mouse.png')
    mousesprite.set_position(janela.width / 2 - mousesprite.width / 2, janela.height / 2 - mousesprite.height / 2)
    mousehitbox = Sprite('1x1.png')
    mouse.hide()
    while True:
        mouse_position = mouse.get_position()
        mousesprite.set_position(mouse_position[0], mouse_position[1])
        mousehitbox.set_position(mousesprite.x, mousesprite.y)
        # inputs
        esc_pressed_now = teclado.key_pressed('esc')
        mb1_pressed_now = mouse.is_button_pressed(1)
        if esc_pressed_past and not esc_pressed_now:
            return 'jogar'
        if not mb1_pressed_now and mb1_pressed_past:
            if mousehitbox.collided_perfect(botao_sair):
                return ''
        esc_pressed_past = teclado.key_pressed('esc')
        mb1_pressed_past = mouse.is_button_pressed(1)
        # updates
        botao_sair.draw()
        # draw