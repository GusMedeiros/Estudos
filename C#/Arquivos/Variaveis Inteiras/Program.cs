/* inteiros com sinal tem 2^b numeros representáveis, sendo metade para negativos, 1 para zero, metade - 1 para positivos, em
b é o número de bits da variável utilizada.*/

short inteiro16BitsComSinal = (short)(-1 * Math.Pow(2, 16)/2);// funciona, pois está dentro (no limite) do intervalo [-2^16/2 , 2^16/2). 
Console.WriteLine($"short normal: {inteiro16BitsComSinal}");
inteiro16BitsComSinal -= 1; // esperado que ocorra overflow ou algum erro, já que excede o número de bits necessário.
Console.WriteLine($"short com overflow: {inteiro16BitsComSinal}");
/* Valor que deveria ser representado: -32769
Valor que aparece: +32767. Isso ocorre pois, em complemento de 2, o valor -32768 é 1000 0000 0000 0000, e, ao subtrair 1,
obtemos 0111 1111 1111 1111, que em decimal é justamente 32767.*/
ushort inteiro16BitsSemSinal = (ushort) (Math.Pow(2, 16) - 1);
Console.WriteLine($"ushort normal: {inteiro16BitsSemSinal}"); // tudo certo, pois cabe (por pouco) em 16 bits.
inteiro16BitsSemSinal += 1; // esperado que ocorra overflow ou algum erro, já que excede 2^16 - 1.
Console.WriteLine($"ushort com overflow: {inteiro16BitsSemSinal}");
/* Valor suposto: 65536. Valor real: 0, pois 1111 1111 1111 1111 + 1 = 1 0000 0000 0000 0000, porém o bit 1 está fora dos 16
bits, resultando em overflow e sendo desconsiderado, ou seja, o computador lê 0000 0000 0000 0000. */
int inteiro32BitsComSinal = (int) (Math.Pow(2,32)/ 2) - 1;
Console.WriteLine($"int normal : {inteiro32BitsComSinal}");
inteiro32BitsComSinal += 1;
Console.WriteLine($"int com overflow: {inteiro32BitsComSinal}");
uint inteiro32BitsSemSinal = (uint) (Math.Pow(2,32)) - 1;
Console.WriteLine($"uint normal : {inteiro32BitsSemSinal}");
inteiro32BitsSemSinal += 1;
Console.WriteLine($"uint com overflow: {inteiro32BitsSemSinal}");
long inteiro64BitsComSinal = (long) (Math.Pow(2, 64) / 2) - 1;
Console.WriteLine($"long normal: {inteiro64BitsComSinal}");
inteiro64BitsComSinal += 1;
Console.WriteLine($"long com overflow: {inteiro64BitsComSinal}");
ulong inteiro64BitsSemSinal = (ulong) Math.Pow(2,64) - 1;
Console.WriteLine($"ulong normal: {inteiro64BitsSemSinal}");
inteiro64BitsSemSinal += 1;
Console.WriteLine($"ulong com overflow: {inteiro64BitsSemSinal}");