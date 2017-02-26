using System;

namespace SPOJ
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; (i = Convert.ToInt32(Console.ReadLine())) != 42;)
                Console.WriteLine(i);
        }
    }
}
