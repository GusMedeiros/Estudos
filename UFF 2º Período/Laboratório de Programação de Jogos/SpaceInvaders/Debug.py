class Debug:

    def __init__(self, janela, debugstate: bool):
        self.janela = janela
        self.debugstate = debugstate
        self.fps = self.cronometro_s = self.frames_acumulados = 0
        self.f3_past = False

    def show_fps(self):
        if self.debugstate:
            self.janela.draw_text(str(int(self.fps)), self.janela.width - 160, 45, 45, (255, 255, 0))
        if self.cronometro_s < 0.35:
            self.cronometro_s += self.janela.delta_time()
            self.frames_acumulados += 1
        else:
            self.fps = self.frames_acumulados / self.cronometro_s
            self.cronometro_s = self.frames_acumulados = 0

    def check_f3_and_toggle(self):
        if not self.janela.keyboard.key_pressed('f3') and self.f3_past:
            self.debugstate = not self.debugstate
        self.f3_past = self.janela.keyboard.key_pressed('f3')

    def show_fps_if_debug(self):
        self.check_f3_and_toggle()
        self.show_fps()