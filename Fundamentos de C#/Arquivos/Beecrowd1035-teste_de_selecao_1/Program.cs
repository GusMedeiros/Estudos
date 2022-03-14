/* Leia 4 valores inteiros A, B, C e D. A seguir, se B for maior do que C e se D for maior do que A, e a soma de C com D for
maior que a soma de A e B e se C e D, ambos, forem positivos e se a variável A for par escrever a mensagem "Valores aceitos", 
senão escrever "Valores nao aceitos".

Entrada
Quatro números inteiros A, B, C e D.

Saída
Mostre a respectiva mensagem após a validação dos valores. 
Exemplo de Entrada	
5 6 7 8
Exemplo de Saída
Valores nao aceitos*/
string[] strings = Console.ReadLine().Split();
int A = int.Parse(strings[0]); int B = int.Parse(strings[1]); int C = int.Parse(strings[2]); int D = int.Parse(strings[3]);
if (B > C && D > A && (C+D > A) && (C+D) > (A+B) && C>=0 && D >= 0) {
    Console.WriteLine("Valores aceitos");
}
else Console.WriteLine("Valores nao aceitos");
