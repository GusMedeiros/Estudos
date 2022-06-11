from PPlay.sprite import Sprite
from PPlay.gameimage import GameImage
from ranking import Ranking
from Debug import Debug

class Menu:
    caminhosprites = 'MenuInicial/'

    def __init__(self, janela):
        self.janela = janela
        self.ranking = Ranking(janela)
        # inputs e relacionados
        self.mouse = janela.get_mouse()
        self.mousesprite = Sprite(f'{self.caminhosprites}mouse.png')
        self.mousehitbox = Sprite(f'{self.caminhosprites}/1x1.png')
        self.teclado = janela.get_keyboard()
        self.esc_pressed_past = self.mb1_pressed_past = False
        self.double_esc_prevention = True
        # botoes
        self.botao_jogar = Sprite(f'{self.caminhosprites}Botaojogar.png', 2)
        self.botao_sair = Sprite(f'{self.caminhosprites}botaosair.png', 2)
        self.botao_retornar = Sprite(f'{self.caminhosprites}botaoretornar.png', 2)
        self.botao_menu_principal = Sprite(f'{self.caminhosprites}botaomenuprincipal.png', 2)

    def menuinicial(self, debug=None):
        fundo = GameImage(f'{self.caminhosprites}espaco.jpg')
        # mouse
        self.mousesprite.set_position(self.janela.width / 2 - self.mousesprite.width / 2,
                                      self.janela.height / 2 - self.mousesprite.height / 2)
        self.mouse.hide()
        mb1click2 = False
        # jogar
        # ranking
        botaoranking = Sprite(f'{self.caminhosprites}Botaoranking.png', 2)
        # sair
        botaosair = Sprite(f'{self.caminhosprites}Botaosair.png', 2)
        # dificuldade
        botaodificuldade = Sprite(f'{self.caminhosprites}Botaodificuldade.png', 2)
        dificuldadeslista = ["Fácil", "Médio", "Difícil"]
        dificuldadeindice = 0
        dificuldade = dificuldadeslista[0]
        tamanhofonte = 28

        # posicoes dos botões
        self.botao_jogar.set_position(self.janela.width * 0.825 - self.botao_jogar.width/2, self.janela.height * 1/10)
        botaodificuldade.set_position(self.botao_jogar.x, self.botao_jogar.y + self.botao_jogar.height * 1.3)
        botaoranking.set_position(self.botao_jogar.x, botaodificuldade.y + self.botao_jogar.height * 1.3)
        botaosair.set_position(self.botao_jogar.x, botaoranking.y + self.botao_jogar.height * 1.3)
        #
        while True:
            posicao = self.mouse.get_position()
            # inputs do mouse
            self.mousesprite.set_position(posicao[0], posicao[1])
            self.mousehitbox.set_position(posicao[0], posicao[1])
            mb1click = self.mouse.is_button_pressed(1)
            # checar botao apertado
            if True:  # if redundante proposital, para que dê pra colapsar todos os ifs abaixo de uma vez no pycharm:
                # botao jogar
                if self.mousehitbox.collided(self.botao_jogar):
                    self.botao_jogar.set_curr_frame(1)
                    if not mb1click and mb1click2:
                        # animacaojogar()
                        return dificuldade
                else:
                    self.botao_jogar.set_curr_frame(0)
                # botao dificuldade
                if self.mousehitbox.collided(botaodificuldade):
                    botaodificuldade.set_curr_frame(1)
                    if not mb1click and mb1click2:
                        dificuldadeindice += 1
                        dificuldade = dificuldadeslista[dificuldadeindice % 3]
                else:
                    botaodificuldade.set_curr_frame(0)
                # botao ranking
                if self.mousehitbox.collided(botaoranking):
                    botaoranking.set_curr_frame(1)
                    if not mb1click and mb1click2:
                        self.ranking.drawstate = not self.ranking.drawstate
                elif not self.ranking.drawstate:
                    botaoranking.set_curr_frame(0)
                # botao sair
                if self.mousehitbox.collided(botaosair):
                    botaosair.set_curr_frame(1)
                    if not mb1click and mb1click2:
                        # animacaosair()?
                        return "Sair"
                else:
                    botaosair.set_curr_frame(0)
            mb1click2 = self.mouse.is_button_pressed(1)
            # updates
            self.janela.update()
            # draws
            fundo.draw()
            self.botao_jogar.draw()
            botaodificuldade.draw()
            self.janela.draw_text(dificuldade, botaodificuldade.x + 20,
                                  botaodificuldade.y + botaodificuldade.height * 0.74, tamanhofonte)
            botaoranking.draw()
            botaosair.draw()
            # ranking caso on
            if self.ranking.drawstate:
                self.ranking.animacao(1)
                botaoranking.set_curr_frame(1)
            else:
                self.ranking.animacao(-1)
            if debug:
                debug.show_fps_if_debug()
            # mouse sempre por último:
            self.mousesprite.draw()
            self.mousehitbox.draw()

    def menupause(self):
        self.botao_retornar.set_position(self.janela.width - self.botao_retornar.width, self.janela.height/2)
        self.botao_menu_principal.set_position(self.botao_retornar.x, self.botao_retornar.y +
                                               self.botao_menu_principal.height * 1.1)
        self.mouse.hide()
        # while True:
        # inputs
        mouse_position = self.mouse.get_position()
        self.mousesprite.set_position(mouse_position[0], mouse_position[1])
        self.mousehitbox.set_position(mouse_position[0], mouse_position[1])
        esc_pressed_now = self.teclado.key_pressed('esc')
        mb1_pressed_now = self.mouse.is_button_pressed(1)
        # esc (resume)
        if not self.esc_pressed_past and not esc_pressed_now:
            self.double_esc_prevention = False
        if self.esc_pressed_past and not esc_pressed_now and not self.double_esc_prevention:
            return 'jogar'
        # botao retornar
        if self.mousehitbox.collided(self.botao_retornar):
            self.botao_retornar.set_curr_frame(1)
            if self.mb1_pressed_past and not mb1_pressed_now:
                return 'jogar'
        else:
            self.botao_retornar.set_curr_frame(0)
        # botao menu principal
        if self.mousehitbox.collided(self.botao_menu_principal):
            self.botao_menu_principal.set_curr_frame(1)
            if self.mb1_pressed_past and not mb1_pressed_now:
                return 'mainmenu'
        else:
            self.botao_menu_principal.set_curr_frame(0)
        self.esc_pressed_past = self.teclado.key_pressed('esc')
        self.mb1_pressed_past = self.mouse.is_button_pressed(1)
        # updates
        self.botao_retornar.draw()
        self.botao_menu_principal.draw()
        self.mousesprite.draw()
        self.mousehitbox.draw()
        return False  # se chegou até aqui, jogando deve continuar falso.

    def pedir_nome(self, debug=None):
        import pygame
        nome = ''
        backspace_cronometro = 0
        campo_nome = Sprite(f'{self.caminhosprites}botaopequenovazio.png', 2)
        campo_nome.set_position(self.janela.width/2 - 210, self.janela.height/2 - 3)
        pressed_past = [False for i in range(26)]
        space_pressed_past = backspace_pressed_past = False
        fundo = GameImage(f'{self.caminhosprites}espaco.jpg')
        letra_atual = ''
        while not self.teclado.key_pressed('enter'):
            nome_maxsize = 11
            self.janela.update()
            fundo.draw()
            campo_nome.draw()
            self.janela.draw_text(f"PLAYER NAME:", self.janela.width/2 - 150, self.janela.height/2,
                                  50, (0, 246, 245))
            self.janela.draw_text(f"{nome}", self.janela.width/2 - 150, self.janela.height/2 + 50,
                                  48, (255, 255, 255))
            letra_atual = 'A'
            for i in range(26):
                letra_atual = chr(ord('A') + (ord(letra_atual) + 1) % ord('A') % 26)
                if self.teclado.key_pressed(letra_atual) and not pressed_past[i]\
                        and len(nome) < nome_maxsize:
                    nome += letra_atual
                elif nome:
                    # if nome cumpre dois propositos: nao deixar o primeiro char ser espaço e evitar crash com nome[-1]
                    if self.teclado.key_pressed('space') and not space_pressed_past\
                            and len(nome) < nome_maxsize and nome[-1] != ' ':
                        nome += ' '
                    elif self.teclado.key_pressed('backspace') and not backspace_pressed_past \
                            and len(nome) > 0:
                        nome = nome[:-1]

                pressed_past[i] = self.teclado.key_pressed(letra_atual)
                space_pressed_past = self.teclado.key_pressed('space')
                backspace_pressed_past = self.teclado.key_pressed('backspace')
            if debug:
                debug.show_fps_if_debug()
        return nome
