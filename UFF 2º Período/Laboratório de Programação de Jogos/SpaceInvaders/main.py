from MenuInicial.menu import Menu
from PPlay.window import Window
from PPlay.sprite import Sprite
from PPlay.gameimage import GameImage
from Entidades import Player, Tiro
# variáveis de debug
debug = True
fps = 0
cronometro_s = 0
frames_acumulados_1s = 0
# variáveis de jogo
janela = Window(1366, 768)
mouse = janela.get_mouse()
teclado = janela.get_keyboard()
menu = Menu(janela)
rodando = False
fundojogo = GameImage('MenuInicial/espaco.jpg')
while True:
    janela.update()
    dificuldade = menu.menuinicial()
    if not dificuldade or dificuldade == 'Sair':
        exit()
    else:
        rodando = True

    if rodando:
        player = Player(Sprite('Player.png'), dificuldade)
        player.set_position(janela.width / 2 - player.sprite.width / 2, janela.height - player.sprite.height)
        reload_timecounter = player.tiros_delay
        esc_pressed_past = False

    while rodando:
        janela.update()
        # inputs:
        esc_pressed_now = teclado.key_pressed('esc')
        if esc_pressed_now and not esc_pressed_past:
            jogando = False
            menu.mouse.set_position(janela.width/2, janela.height * 3/10)
            menu.esc_pressed_past = menu.mb1_pressed_past = False
            menu.double_esc_prevention = True
            while not jogando:
                fundojogo.draw()
                player.draw()
                Tiro.draw()
                jogando = menu.menupause()
                janela.update()
                if debug:
                    janela.draw_text(str(int(fps)), janela.width - 160, 45, 45, (255, 255, 0))
                    if cronometro_s < 0.35:
                        cronometro_s += janela.delta_time()
                        frames_acumulados_1s += 1
                    else:
                        fps = frames_acumulados_1s / cronometro_s
                        cronometro_s = frames_acumulados_1s = 0
        esc_pressed_past = teclado.key_pressed('esc')
        if teclado.key_pressed('left'):
            if player.x > 0:
                player.x -= player.velX * janela.delta_time()
            else:
                player.x = 0
        if teclado.key_pressed('right'):
            if player.x + player.width < janela.width:
                player.x += player.velX * janela.delta_time()
            else:
                player.x = janela.width - player.width
        if teclado.key_pressed('space'):
            if reload_timecounter >= player.tiros_delay:
                Tiro(Sprite('tiro.png'), player.x + player.width/2, player.y)
                reload_timecounter = 0
        # updates:
        reload_timecounter += janela.delta_time()
        # debug updates:
        if debug:
            if cronometro_s < 0.35:
                cronometro_s += janela.delta_time()
                frames_acumulados_1s += 1
            else:
                fps = frames_acumulados_1s / cronometro_s
                cronometro_s = frames_acumulados_1s = 0
        # draws
        fundojogo.draw()
        Tiro.update_and_draw(janela)
        player.draw()
        # debug draws
        if debug:
            janela.draw_text(str(int(fps)), janela.width - 160, 45, 45, (255, 255, 0))
