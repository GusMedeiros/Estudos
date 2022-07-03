class Ranking:
    caminho_ranking = "ranking.txt"
    caminho_sprite = "MenuInicial/Botao Grande Vazio.png"
    caminho_scroll = "MenuInicial/scrollbar.png"

    def __init__(self, janela):
        from PPlay.sprite import Sprite
        from os.path import exists
        from pygame.font import Font
        from os import getcwd
        self.drawstate = False
        self.drawfinished = False
        self.janela = janela
        self.fonte = Font(f'{getcwd()}\\FreePixel.ttf', 30)
        self.scroll = Sprite(self.caminho_scroll)
        self.paralelogramo = Sprite(self.caminho_sprite)
        self.paralelogramo.xoriginal = 0 - self.paralelogramo.width - self.scroll.width - 5
        self.paralelogramo.set_position(self.paralelogramo.xoriginal, 4)
        if not exists(self.caminho_ranking):
            arquivo = open(self.caminho_ranking, "w")
            arquivo.close()
        arquivo = open(self.caminho_ranking, "r", encoding='utf-8')
        self.RAMrank = [linha for i, linha in enumerate(arquivo) if i <= 10]
        arquivo.close()
        self.qtdparalelogramos = self.janela.height // (self.paralelogramo.height + 4)
        self.inicio = 0
        self.scroll_cronometro = 0

    def saverank(self):
        self.RAMrank.sort(key=lambda l: int(l.split("|")[0]), reverse=True)
        self.RAMrank.sort(key=lambda l: (l.split("|")[2][2]), reverse=True)
        from os import remove, rename
        arquivo_temp = open(self.caminho_ranking + "temp", "w", encoding="utf-8")
        for i, linha in enumerate(self.RAMrank):
            arquivo_temp.write(linha.rstrip())
            if i != len(self.RAMrank) - 1:  # se nao for o ultimo elemento, pula linha.
                arquivo_temp.write("\n")
        arquivo_temp.close()
        remove(self.caminho_ranking)
        rename(self.caminho_ranking + "temp", self.caminho_ranking)

    def updaterank(self, score, nome, dificuldade):
        self.RAMrank.append(f"{score}|{nome}|{dificuldade}")
        self.RAMrank.sort(key=lambda x: x.split("|")[0])

    def animacao(self, direcao):
        velX = self.paralelogramo.width * 2 * direcao

        for i in range(self.qtdparalelogramos):
            self.paralelogramo.draw()
            i += self.inicio

            if 0 <= i < len(self.RAMrank):
                rank = self.RAMrank[i].rstrip().split('|')
                texto = f'{i+1}º Lugar | Pontos: {rank[0]:5}| Dificuldade: {rank[2]:7}'
                texto2 = f'Nome: {rank[1]}'
                self.janela.draw_text(texto, self.paralelogramo.x + 40, self.paralelogramo.y + 10, 30, (0, 246, 245),
                                      bold=True, font=self.fonte)
                self.janela.draw_text(texto2, self.paralelogramo.x + 23, self.paralelogramo.y + 40, 30, (0, 246, 245),
                                      bold=True, font=self.fonte)

            self.paralelogramo.y += self.paralelogramo.height + 4
        self.paralelogramo.y = 4
        self.scroll.x = self.paralelogramo.x + self.paralelogramo.width + 5
        self.scroll.y = self.paralelogramo.y + 10
        self.scroll.draw()
        # mover paralelogramos para a direita
        if direcao > 0:
            if self.paralelogramo.x < self.janela.width / 25:  # se n tiver terminado
                self.paralelogramo.x += velX * self.janela.delta_time()
                self.drawstate = True
        # mover paralelogramos para a esquerda
        else:
            self.drawstate = False
            if self.paralelogramo.x > self.paralelogramo.xoriginal:
                self.paralelogramo.x += velX * self.janela.delta_time()

    def draw(self):
        for linha in self.RAMrank:
            linha = linha.split("|")
