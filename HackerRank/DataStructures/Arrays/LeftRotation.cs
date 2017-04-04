using System;

namespace HackerRank
{
    class Solution
    {
        static void Main(string[] args)
        {
            int n, d;
            {
                var strs = Console.ReadLine().Split(' ');
                n = int.Parse(strs[0]);
                d = int.Parse(strs[1]);
            }
            d = d % n;
            var arr = new int[n];
            {
                var strs = Console.ReadLine().Split(' ');
                for (int i = 0; i < n; ++i)
                    arr[i] = int.Parse(strs[i]);
            }
            if (d != 0)
            {
                var temp = new int[d];
                for (int i = 0; i < n; ++i)
                {
                    if (i < d)
                    {
                        temp[i] = arr[i];
                        continue;
                    }
                    arr[i - d] = arr[i];
                }
                for (int i = 0; i < d; ++i)
                    arr[n - d + i] = temp[i];
            }
            for (int i = 0; i < n; ++i)
                Console.Write(arr[i] + " ");
        }
    }
}
