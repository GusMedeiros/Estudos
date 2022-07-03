from MenuInicial.menu import Menu
from PPlay.window import Window
from PPlay.gameimage import GameImage
from Entidades import Player, Tiro, Enemy
from Debug import Debug
from ranking import Ranking
# variáveis de jogo
janela = Window(1366, 768)
mouse = janela.get_mouse()
teclado = janela.get_keyboard()
menu = Menu(janela)
rodando = False
fundojogo = GameImage('MenuInicial/espaco.jpg')
# variáveis de debug
debug = Debug(janela, True)
ranking = Ranking(janela)
while True:
    janela.update()
    dificuldade = menu.menuinicial(debug)
    if not dificuldade or dificuldade == 'Sair':
        exit()
    else:
        rodando = True

    player = Player(dificuldade, janela)
    player.set_position(janela.width / 2 - player.width / 2, janela.height - player.height)
    Tiro.tiros_player = []
    reload_timecounter = player.tiros_delay
    esc_pressed_past = False
    Enemy.reset()
    Enemy.spawn(dificuldade, 12, 10)
    Enemy.set_difficulty(dificuldade)
    score = 0
    nome_jogador = menu.pedir_nome(debug)
    f3_pressed_past = False

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
                    debug.show_fps_if_debug()
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
                Tiro(1, player.x + player.width / 2, player.y)
                reload_timecounter = 0
        f3_pressed_past = teclado.key_pressed('f3')

        # updates:
        reload_timecounter += janela.delta_time()
        score += Enemy.checar_hit(Tiro.tiros_player)
        player.checar_hit(Tiro.tiros_enemy)
        player.update_invulnerabilidade()
        if Enemy.qtdvivos == 0:
            Enemy.proxima_fase(dificuldade)

        if Enemy.isgameover(player):
            ranking.updaterank(score, nome_jogador, dificuldade)
            ranking.saverank()
            ranking = Ranking(janela)
            menu.ranking = ranking
            menu.gameover(score)
            break
        Enemy.colisao_parede(janela.width, janela.delta_time())
        # draws
        fundojogo.draw()
        Enemy.desenhar_e_update(janela.delta_time())
        Tiro.clear_and_draw(janela)
        janela.draw_text(f'Score:{score}', janela.width * 1/12, janela.height * 1/12, size=45,
                         color=(255, 255, 255), font=menu.ranking.fonte)
        janela.draw_text(f'Fase atual:{Enemy.fase_atual}/{Enemy.fase_maxima}', janela.width * 1 / 12, janela.height * 1.6 / 12, size=45,
                         color=(255, 255, 255), font=menu.ranking.fonte)
        player.drawvidas()
        player.draw()
        # debug draws
        if debug:
            debug.show_fps_if_debug()
