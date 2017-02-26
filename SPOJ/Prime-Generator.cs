using System;

namespace SPOJ
{
    class Program
    {
        static bool is_prime(int num)
        {
            bool res = num != 1;
            for (int i = 2; res && i <= (int)Math.Sqrt(num); ++i)
                res = num % i != 0;
            return res;
        }

        static void Main(string[] args)
        {
            var delim = new char[1] { ' ' };
            for (var segments = Convert.ToInt32(Console.ReadLine()); segments > 0; --segments)
            {
                var strs = Console.ReadLine().Split(delim);
                var ls = Convert.ToInt32(strs[0]);
                var rs = Convert.ToInt32(strs[1]);
                for (; ls <= rs; ++ls)
                {
                    if (is_prime(ls))
                        Console.WriteLine(ls);
                }
                Console.WriteLine();
            }
        }
    }
}
