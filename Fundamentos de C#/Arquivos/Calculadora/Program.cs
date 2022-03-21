void menu(double? resultado)
{
    if (resultado == null)
    {
        Console.Clear();
        Console.WriteLine("Bem-vindo à calculadora!!");
        Console.WriteLine("Selecione a operação desejada:");
    }

    Console.WriteLine("=================================");
    Console.WriteLine("Digite:");
    Console.WriteLine("+ para somar");
    Console.WriteLine("- para subtrair");
    Console.WriteLine("* para multiplicar");
    Console.WriteLine("/ para dividir");
    Console.WriteLine("^ para potenciar");
    Console.WriteLine("v para radiciar");
    Console.WriteLine("S para sair da calculadora");
    Console.WriteLine("================================");
    Console.Write("-> ");
}
double? somar(double? resultado)
{
    double v1;
    if (resultado == null) // será null quando for a primeira operação feita na execução
    {
        Console.WriteLine("Insira o valor 1: ");
        v1 = double.Parse(Console.ReadLine());
    }
    else v1 = (double)resultado; // quando não for a primeira operação, a operação será realizada no resultado anterior.

    Console.WriteLine("Insira o valor 2: ");
    double v2 = double.Parse(Console.ReadLine());

    resultado = v1 + v2;
    return resultado;
}
double? subtrair(double? resultado)
{
    double v1;
    if (resultado == null) // será null quando for a primeira operação feita na execução
    {
        Console.WriteLine("Insira o valor 1: ");
        v1 = double.Parse(Console.ReadLine());
    }
    else v1 = (double)resultado; // quando não for a primeira operação, a operação será realizada no resultado anterior.

    Console.WriteLine("Insira o valor 2: ");
    double v2 = double.Parse(Console.ReadLine());

    resultado = v1 - v2;
    return resultado;
}
double? multiplicar(double? resultado)
{
    double v1;
    if (resultado == null) // será null quando for a primeira operação feita na execução
    {
        Console.WriteLine("Insira o valor 1: ");
        v1 = double.Parse(Console.ReadLine());
    }
    else v1 = (double)resultado; // quando não for a primeira operação, a operação será realizada no resultado anterior.

    Console.WriteLine("Insira o valor 2: ");
    double v2 = double.Parse(Console.ReadLine());

    resultado = v1 * v2;
    return resultado;
}
double? dividir(double? resultado)
{
    double v1;
    if (resultado == null) // será null quando for a primeira operação feita na execução
    {
        Console.WriteLine("Insira o valor 1: ");
        v1 = double.Parse(Console.ReadLine());
    }
    else v1 = (double)resultado; // quando não for a primeira operação, a operação será realizada no resultado anterior.

    Console.WriteLine("Insira o valor 2: ");
    double v2 = double.Parse(Console.ReadLine());
    if (v2 == 0)
    {
        Console.Clear();
        Console.WriteLine("ERRO: NÃO É POSSÍVEL DIVIDIR POR ZERO!!");
        return null;
    }
    resultado = v1 / v2;
    return resultado;
}
double? potenciar(double? resultado)
{
    double v1;
    if (resultado == null) // será null quando for a primeira operação feita na execução
    {
        Console.WriteLine("Insira o valor 1: ");
        v1 = double.Parse(Console.ReadLine());
    }
    else v1 = (double)resultado; // quando não for a primeira operação, a operação será realizada no resultado anterior.

    Console.WriteLine("Insira o valor 2: ");
    double v2 = double.Parse(Console.ReadLine());

    resultado = Math.Pow(v1, v2);
    return resultado;
}
double? radiciar(double? resultado)
{
    double v1;
    if (resultado == null) // será null quando for a primeira operação feita na execução
    {
        Console.WriteLine("Insira o valor 1: ");
        v1 = double.Parse(Console.ReadLine());
    }
    else v1 = (double)resultado; // quando não for a primeira operação, a operação será realizada no resultado anterior.

    Console.WriteLine("Insira o valor 2: ");
    double v2 = double.Parse(Console.ReadLine());

    resultado = Math.Pow(v1, 1 / v2);
    return resultado;
}

double? resultado = null;
do
{
    menu(resultado);
    char operacao = Console.ReadKey().KeyChar;
    Console.WriteLine();
    switch (operacao)
    {
        case '+':
            resultado = somar(resultado);
            break;
        case '-':
            resultado = subtrair(resultado);
            break;
        case '*':
            resultado = multiplicar(resultado);
            break;
        case '/':
            resultado = dividir(resultado);
            break;
        case '^':
            resultado = potenciar(resultado);
            break;
        case 'v':
            resultado = radiciar(resultado);
            break;
        case 's':
        case 'S':
            resultado = null;
            break;
        default:
            Console.WriteLine("ERRO: OPERAÇÃO INVÁLIDA!");
            break;
    }
    if (resultado != null)
        Console.Clear();
    Console.WriteLine($"{(resultado == null ? "Obrigado por usar a calculadora!!" : "Resultado:")}");
    Console.WriteLine(resultado);
} while (resultado != null);
Console.ReadLine();