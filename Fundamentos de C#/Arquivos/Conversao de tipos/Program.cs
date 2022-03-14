int inteiro = 100;
float real = inteiro + 300; // conversão implicita. Inteiro = 100 virou 100.0f automaticamente.
//inteiro = (int) real; // por coerção
//inteiro = int.Parse(real.ToString()); // como parse só aceita string, é necessário usar o ToString para funcionar.
//inteiro = Convert.ToInt32(real); // conversão explícita através do convert.
Console.WriteLine(inteiro.ToString() +' '+ real.ToString());
int valor = int.Parse("65");
float valor2 = 34.6f;
Console.WriteLine(Convert.ToInt32(valor2));
Console.WriteLine((char)valor);
