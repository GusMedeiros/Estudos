static int Quadrado(int parametro)
{
    return parametro * parametro;
}

Console.WriteLine(Quadrado(2));

static string RetornaNome(string nome, string sobrenome, int? idade = null)
{
    return $"{nome} {sobrenome}{(idade==null?null:$" {idade}")}";
}

Console.WriteLine(RetornaNome("Gustavo", "Medeiros"));
Console.WriteLine(RetornaNome("Gustavo", "Medeiros", 21));

static string Hoje()
{
    return DateTime.Today.ToShortDateString();
}
Console.WriteLine($"Hoje é {Hoje()}");
