class Program
{
    static void Main()
    {
        List<string> listOfStrings = new List<string> { "apple", "banana", "apple", "orange", "banana" };

        // Remove duplicates
        List<string> distinctList = listOfStrings.Distinct().ToList();

        // Print the result
        foreach (var item in distinctList)
        {
            Console.WriteLine(item);
        }
    }
}