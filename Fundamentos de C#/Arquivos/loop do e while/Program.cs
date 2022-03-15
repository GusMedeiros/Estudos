Console.WriteLine("Claudinho:\nDuvido você contar até 10 que nem eu, Joãozinho!.");
int contagem = 0;
do
{
    if (contagem < 10)
        Console.Write($"{contagem}, ");
    else
        Console.WriteLine($"{contagem}.");
    contagem++;
} while (contagem < 11);

Console.WriteLine("Joãozinho:\nAh, é? Eu sei contar até 20, olha!");
contagem = 0;
while (contagem < 21)
{
    if (contagem < 20)
        Console.Write($"{contagem}, ");
    else
        Console.WriteLine($"{contagem}.");
    contagem++;
}
