# normalmente, para criar um vetor de 1 até 10, um
# programador teria que fazer algo como:
# vetor = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# em R, podemos simplesmente fazer:
vetor1 <- 1:10
vetor2 <- 1:10
print(vetor1)

# como pode ver, cria-se um vetor de 1 a 10 de maneira prática.

# Podemos somar elementos de mesmo índice de vetores com +:
print(vetor1 + vetor2)

# O mesmo se aplica aos outros operadores:

print(vetor1 - vetor2)
print(vetor1 * vetor2)
print(vetor1 / vetor2)
print(vetor1 ^ vetor2)
print(vetor1 %% vetor2)
print(vetor1 %/% vetor2)

# Operador IN: retorna true ou false caso o elemento esteja contido

print(10 %in% vetor1)
print(11 %in% vetor1)
# pode ser usado de forma vetorizada:

print(vetor1 %in% vetor2)

# LEMBRETE: APRENDER O OPERADOR %*%