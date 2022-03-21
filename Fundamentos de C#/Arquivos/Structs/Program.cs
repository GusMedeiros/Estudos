var chromebook = new Product("Chromebook", 1, 529.99m);
Console.WriteLine($"You just bought a {chromebook.Name} for {chromebook.PriceInBRL(0.2m).ToString("c2")} brazilian reais.");
struct Product 
{
    // Propriedades
    public string Name;
    public int Id;
    public decimal Price;
    // Métodos
    public Product(string name,int id, decimal price)
    {
        Id = id;
        Name = name;
        Price = price;
    }
    public decimal PriceInBRL(decimal brl)
    {
        return Decimal.Multiply(brl, Price);
    }
}

