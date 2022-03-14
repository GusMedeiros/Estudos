float pontoFlutuante = 17.03F;
decimal numeroDecimal = 17.03M;

numeroDecimal -= 17;
pontoFlutuante -= 17;
Console.WriteLine($"{numeroDecimal} = {pontoFlutuante}? {numeroDecimal == (decimal)pontoFlutuante}");