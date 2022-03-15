Console.WriteLine("Bem-vindo ao testador de maioridade.");
Console.WriteLine("Você deseja saber se é maior de idade em que país?");
Console.WriteLine("=============");
Console.WriteLine("1: BRASIL");
Console.WriteLine("2: EUA");
Console.WriteLine("3: NORUEGA");
Console.WriteLine("4: TODOS");
Console.WriteLine("5: NENHUM. SAIR");
Console.WriteLine("=============");
byte opcao = byte.Parse(Console.ReadLine());

switch (opcao)
{
    case 1:
        Paises.Brasil = true;
        break;
    case 2:
        Paises.Eua = true;
        break;
    case 3:
        Paises.Noruega = true;
        break;
    case 4:
        Paises.Brasil = Paises.Eua = Paises.Noruega = Paises.Todos = true;
        break;
    default:
        Paises.Nenhum = true;
        break;
}
Console.Write($"{(Paises.Nenhum ? "Você pediu para sair." : "Você pediu o")}{(Paises.Todos ? "s" : "")} {(Paises.Nenhum ? "" : "seguinte")}");
Console.WriteLine($"{(Paises.Todos ? "s" : "")} {(Paises.Nenhum ? "" : "país")}{(Paises.Todos ? "es" : "")}{(Paises.Nenhum ? "Saindo..." : ":")}");
Console.Write($"{(Paises.Brasil ? "Brasil" : "")}{(Paises.Todos ? ", " : "")}{(Paises.Eua ? "EUA" : "")}");
Console.WriteLine($"{(Paises.Todos ? " e " : "")}{(Paises.Noruega ? "Noruega." : "")}");
if (!Paises.Nenhum)
{

    Console.Write("Insira sua idade: ");
    byte idade = byte.Parse(Console.ReadLine());
    Console.WriteLine("Você é maior de idade em: ");
    if (idade >= Paises.MaioridadeBrasil && Paises.Brasil)
    {
        Console.WriteLine("Brasil");
    }
    if (idade >= Paises.MaioridadeEua && Paises.Eua)
    {
        Console.WriteLine("Eua");
    }
    if (idade >= Paises.MaioridadeNoruega && Paises.Noruega)
    {
        Console.WriteLine("Noruega");
    }
    if (idade < Paises.MaioridadeBrasil && idade < Paises.MaioridadeEua && idade < Paises.MaioridadeNoruega)
        Console.WriteLine("Nenhum dos países selecionados.");
}