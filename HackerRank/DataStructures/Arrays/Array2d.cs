using System;

namespace HackerRank
{
    class Program
    {
        static void Main(string[] args)
        {
            const int n = 6;
            var arr = new int[n, n];
            int max_val = -9 * 9;
            for (int i = 0; i < n; ++i)
            {
                var strs = Console.ReadLine().Split(' ');
                for (int j = 0; j < strs.Length; ++j)
                    arr[i, j] = int.Parse(strs[j]);
            }
            for (int i = 0; i + 2 < n; ++i)
                for (int j = 0; j + 2 < n; ++j)
                {
                    int cur_max = 0;
                    for (int k = 0; k < 3; ++k)
                        for (int m = 0; m < 3; ++m)
                            cur_max += (k == 1 && (m == 0 || m == 2) ? 0 : arr[i + k, j + m]);
                    if (max_val < cur_max)
                        max_val = cur_max;
                }
            Console.WriteLine(max_val);
        }
    }
}
