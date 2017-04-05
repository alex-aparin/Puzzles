using System;
using System.Collections.Generic;

namespace HackerRank
{
    class Solution
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var strs = new List<string>(n);
            for (int i = 0; i < n; ++i)
                strs.Add(Console.ReadLine());
            int q = int.Parse(Console.ReadLine());
            var ans = new List<int>(q);
            for (int i = 0; i < q; ++i)
            {
                var query_str = Console.ReadLine();
                int res = 0;
                for (int j = 0; j < strs.Count; ++j)
                {
                    res += strs[j].CompareTo(query_str) == 0 ? 1 : 0;
                }
                ans.Add(res);
            }
            for (int i = 0; i < ans.Count; ++i)
                Console.WriteLine(ans[i]);
        }
    }
}
