from MenuInicial.menu import Menu
from PPlay.window import Window
from PPlay.sprite import Sprite
from PPlay.gameimage import GameImage
from Entidades import Player, Tiro, Enemy
from Debug import Debug
# variáveis de jogo
janela = Window(1366, 768)
mouse = janela.get_mouse()
teclado = janela.get_keyboard()
menu = Menu(janela)
rodando = False
fundojogo = GameImage('MenuInicial/espaco.jpg')
# variáveis de debug
debug = Debug(janela, False)

while True:
    janela.update()
    dificuldade = menu.menuinicial(debug)
    if not dificuldade or dificuldade == 'Sair':
        exit()
    else:
        rodando = True

    if rodando:
        player = Player(Sprite('Player.png'), dificuldade)
        player.set_position(janela.width / 2 - player.sprite.width / 2, janela.height - player.sprite.height)
        Tiro.lista = []
        reload_timecounter = player.tiros_delay
        esc_pressed_past = False
        Enemy.reset()
        Enemy.spawn(dificuldade, 12, 1)

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
                janela.update()
                fundojogo.draw()
                player.draw()
                Enemy.desenhar()
                Tiro.draw()
                jogando = menu.menupause()
                if jogando:
                    break
                if debug:
                    debug.show_fps()
            if jogando == 'mainmenu':
                break
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
        Enemy.checar_hit(Tiro.lista)
        if not Enemy.tem_alien():
            break

        # draws
        fundojogo.draw()
        Enemy.colisao_parede(janela.width, janela.delta_time())
        Enemy.desenhar_e_mover(janela.delta_time())
        Tiro.update_and_draw(janela)
        player.draw()
        # debug draws
        if debug:
            debug.show_fps()
