# experiencias com orientação a objeto :)

class Funcionario:
    cargo = 'Funcionário'
    porcentagem_aumento = 0.04
    salariopadrao = 1300
    qtdFuncionarios = int()
    todos = {}

    def __init__(self, primeiro_nome, sobrenome, salario=salariopadrao):
        self.primeiro_nome = primeiro_nome
        self.sobrenome = sobrenome
        self.salario = salario
        Funcionario.todos[self.nome_completo.lower()] = self
        Funcionario.qtdFuncionarios += 1

    @property
    def email(self):
        return f'{self.primeiro_nome}.{self.sobrenome}@empresa.com'

    @property
    def nome_completo(self):
        return f'{self.primeiro_nome} {self.sobrenome}'

    @nome_completo.setter
    def nome_completo(self, nome):
        nome = nome.split()
        self.primeiro_nome = nome[0]
        self.sobrenome = nome[1]

    @nome_completo.deleter
    def nome_completo(self):
        self.primeiro_nome = None
        self.sobrenome = None

    def aplicar_aumento(self):
        self.salario = float(self.salario * (1 + Funcionario.porcentagem_aumento))

    def definir_aumento_individual(self, num):
        self.porcentagem_aumento = num

    def demitir(self):
        Funcionario.qtdFuncionarios -= 1
        Funcionario.todos.pop(self.nome_completo.lower())
        return 'Funcionário demitido'

    def salario_portugues(self):
        if isinstance(self, float) or isinstance(self, int):
            return str.replace(str.replace(f'{self:_}', '.', ','), '_', '.')
        else:
            return str.replace(str.replace(f'{self.salario:_}', '.', ','), '_', '.')

    def mudar_cargo(self, cls):
        self.demitir()
        return cls(self.primeiro_nome, self.sobrenome)

    def __add__(self, instancia2):
        return self.salario + instancia2.salario

    def __repr__(self):
        return f'Funcionario({self.primeiro_nome}, {self.sobrenome}, {self.salario})'

    def __str__(self):
        return f'{self.nome_completo} - {self.email}'

    @classmethod
    def definir_aumento(cls, num):
        cls.porcentagem_aumento = num

    @classmethod
    def criar_por_string(cls, string):
        """essa função é feita para o seguinte formato de strings:
        'nome-sobrenome-salario'"""
        nome, sobrenome, _salario = string.split('-')
        if _salario:
            _salario = float(_salario)
        return cls(nome, sobrenome, _salario)

    @classmethod
    def achar_por_nome(cls, nome):
        if nome.lower() in cls.todos.keys():
            return cls.todos[nome.lower()]


class Programador(Funcionario):
    Cargo = 'Programador'
    porcentagem_aumento = 0.2
    salario_padrao = 4000

    def __init__(self, primeiro_nome, sobrenome, linguagem, salario=salario_padrao):
        self.linguagem = linguagem
        super().__init__(primeiro_nome, sobrenome, salario)


class Gerente(Funcionario):
    cargo = 'Gerente'
    salariopadrao = 6000

    def __init__(self, primeiro_nome, sobrenome, salario=salariopadrao, gerenciados=None):
        if gerenciados:
            if isinstance(gerenciados, list):
                self.gerenciados = gerenciados
            else:
                self.gerenciados = [gerenciados]
        else:
            self.gerenciados = []
        super().__init__(primeiro_nome, sobrenome, salario)

    def adicionar_gerenciado(self, gerenciado):
        self.gerenciados.append(gerenciado)

    def remover_gerenciado(self, gerenciado):
        self.gerenciados.remove(gerenciado)

    def mostrar_gerenciados(self):
        print('=====================================')
        print(f'Gerenciados do gerente {self.nome_completo}:')
        for gerenciado in self.gerenciados:
            print(f'{gerenciado.nome_completo()}, R${gerenciado.salario_portugues()}')
        print('========= Fim Gerenciados ===========')
