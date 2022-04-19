# dinamicamente tipada, ou seja, n�o precisa declarar o tipo da vari�vel.
# entretanto, isso n�o significa que os tipos n�o existem.
# as vari�veis recebem o valor, e os valores t�m tipos. Vari�veis podem mudar de tipo, valores n�o.



msg <- "Hello world!" # character / string
bool <- TRUE # boolean
numero <- 2 # numeric (float)
numInt <- 2L # integer
numComplex <- 2+5i # complex
stringRaw <- charToRaw(msg) # bytes da string. Como a string � de certa forma um array de caracteres,
# mostrar� os bytes de cada caractere em sequ�ncia.

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
