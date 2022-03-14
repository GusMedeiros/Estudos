/* https://www.beecrowd.com.br/judge/pt/problems/view/1015
Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano, p1(x1,y1) e p2(x2,y2) e 
calcule a distância entre eles, mostrando 4 casas decimais após a vírgula, segundo a fórmula:

Distancia = (imagem visivel no link)

Entrada
O arquivo de entrada contém duas linhas de dados. A primeira linha contém dois valores de ponto flutuante: x1 y1 e a segunda linha contém dois valores de ponto flutuante x2 y2.

Saída
Calcule e imprima o valor da distância segundo a fórmula fornecida, com 4 casas após o ponto decimal.
 */

string[] entrada;
float[,] pontos = new float[2,2];
for (int c = 0; c < 2; c++)
{
    entrada = Console.ReadLine().Split();
    pontos[c, 0] = float.Parse(entrada[0]);
    pontos[c, 1] = float.Parse(entrada[1]);
}
float distancia = (float) Math.Pow(Math.Pow(pontos[0, 0] - pontos[1, 0], 2) + Math.Pow(pontos[0,1] - pontos[1,1], 2), 0.5);

Console.WriteLine(string.Format("{0:0.0000}" ,distancia));
