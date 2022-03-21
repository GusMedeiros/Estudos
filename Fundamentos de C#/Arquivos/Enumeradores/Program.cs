Console.WriteLine("Insert the employee's name: ");
string name = Console.ReadLine();
Console.WriteLine("Insert the employee's branch: ");
string input = Console.ReadLine().ToLower();
input = char.ToUpper(input[0]) + input.Substring(1);
EBranch branch;
switch (input)
{
    case "Scranton":
        branch = EBranch.Scranton;
        break;
    case "Akron":
        branch = EBranch.Akron;
        break;
    case "Albany":
        branch = EBranch.Albany;
        break;
    case "Nashua":
        branch = EBranch.Nashua;
        break;
    default:
        branch = EBranch.Nashua;
        break;
}
Console.WriteLine("Insert the employee's salary: ");
decimal salary = Convert.ToDecimal(Console.ReadLine());

var employee1 = new Employee(name,branch,salary);
Enum.TryParse(input, out EBranch branch2);
var employee2 = new Employee(name,branch2,salary);
Console.WriteLine("You created the following employee:");
Console.WriteLine($"Name: {employee1.Name} | Branch: {employee1.Branch}, ID: {(int)employee1.Branch} | Salary: {employee1.Salary.ToString("c2")}");
Console.WriteLine("Test:");
Console.WriteLine($"Name: {employee2.Name} | Branch: {employee2.Branch}, ID: {(int)employee2.Branch} | Salary: {employee2.Salary.ToString("c2")}");

enum EBranch // enumerator for Dunder Mifflin's branches
{
    Scranton = 1,
    Akron = 2,
    Albany = 3,
    Nashua = 4
}

struct Employee
{
    public string Name;
    public EBranch Branch;
    public decimal Salary;

    public Employee(string name, EBranch branch, decimal salary)
    {
        Name = name;
        Branch = branch;
        Salary = salary;
    }   
}