using System;

namespace HackerRank
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Convert.ToInt32(Console.ReadLine());
            var strs = Console.ReadLine().Split(' ');
            var arr = new int[n];
            for (int i = 0; i < n; ++i)
                arr[i] = Convert.ToInt32(strs[n - i - 1]);
            foreach (var item in arr)
                Console.Write(item + " ");
        }
    }
}
