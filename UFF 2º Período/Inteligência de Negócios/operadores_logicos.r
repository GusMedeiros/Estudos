# https://www.r-bloggers.com/2021/06/think-of-as-a-stricter/

TTFF = c(TRUE, TRUE, FALSE, FALSE)
FTFT = c(FALSE, TRUE, FALSE, TRUE)

# operador AND:
print(TTFF & FTFT)
print(TTFF && FTFT)
# & itera sobre os vetores, comparando pares de elementos.
# && compara somente dois elementos escalares, e retorna um �nico valor escalar.

# operador OR:
print(TTFF | FTFT)
print(TTFF || FTFT)
# similarmente ao &, | � o operador OR aplic�vel a vetores.
# || � o operador OR aplic�vel somente a dois valores escalares.

# operador NOT:
print(!TTFF)
# � sempre vetoriz�vel


# OBS: express�es IF apenas ligam para o primeiro elemento de um vetor de booleanos.
if (ttff | tftf) {
  "O interpretador vai dar um warning."
}
