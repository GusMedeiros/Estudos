class Ranking:
    caminho_ranking = "ranking.json"
    caminho_sprite = "MenuInicial/Botao Grande Vazio.png"

    def __init__(self, janela):
        from PPlay.sprite import Sprite
        self.drawstate = False
        self.drawfinished = False
        self.janela = janela
        self.paralelogramo = Sprite(self.caminho_sprite)
        self.paralelogramo.xoriginal = 0 - self.paralelogramo.width
        self.paralelogramo.set_position(self.paralelogramo.xoriginal, 4)
        arquivo = open(self.caminho_ranking, "w")
        arquivo.close()
        arquivo = open(self.caminho_ranking, "r")
        self.RAMrank = [linha for i, linha in enumerate(arquivo) if i < 10]
        arquivo.close()
        self.qtdparalelogramos = self.janela.height // (self.paralelogramo.height + 4)

    def saverank(self):
        self.RAMrank.sort(key=lambda l: int(l.split("|")[0]), reverse=True)
        from os import remove, rename
        arquivo_temp = open(self.caminho_ranking + "temp", "w", encoding="utf-8")
        for linha in self.RAMrank:
            arquivo_temp.write(linha.rstrip())
            if linha != self.RAMrank[-1]:
                arquivo_temp.write("\n")
        arquivo_temp.close()
        remove(self.caminho_ranking)
        rename(self.caminho_ranking + "temp", self.caminho_ranking)

    def updaterank(self, nome, score):
        self.RAMrank.append(f"{score}|{nome}")
        self.RAMrank.sort(key=lambda x: x.split("|")[0])

    def animacao(self, direcao):
        velX = self.paralelogramo.width * 2 * direcao
        for _ in range(self.qtdparalelogramos):
            self.paralelogramo.draw()
            self.paralelogramo.y += self.paralelogramo.height + 4
        self.paralelogramo.y = 4

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
            print(linha[0], linha[1])
