# dinamicamente tipada, ou seja, não precisa declarar o tipo da variável.
# entretanto, isso não significa que os tipos não existem.
# as variáveis recebem o valor, e os valores têm tipos. Variáveis podem mudar de tipo, valores não.



msg <- "Hello world!" # character / string
bool <- TRUE # boolean
numero <- 2 # numeric (float)
numInt <- 2L # integer
numComplex <- 2+5i # complex
stringRaw <- charToRaw(msg) # bytes da string. Como a string é de certa forma um array de caracteres,
# mostrará os bytes de cada caractere em sequência.

print(msg)
print(class(msg))
print(bool)
print(class(bool))
print(numero)
print(class(numero))
print(numInt)
print(class(numInt))
print(numComplex)
print(class(numComplex))
print(stringRaw)
print(class(stringRaw))
