byte idade = Convert.ToByte((Console.ReadLine()));
const byte maioridade = 21; 
if (idade >= maioridade) 
    Console.WriteLine("Você é maior de idade nos EUA e no Brasil.");
else if (idade >= 18)
    Console.WriteLine("Você é menor de idade nos EUA, porém maior de idade no Brasil.");
else
    Console.WriteLine("Você é menor de idade tanto no Brasil quanto nos EUA.");