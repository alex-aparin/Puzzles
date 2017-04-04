using System;
using System.Collections.Generic;

namespace HackerRank
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, q;
            {
                var strs = Console.ReadLine().Split(' ');
                n = int.Parse(strs[0]);
                q = int.Parse(strs[1]);
            }
            var ans = new List<int>();
            var seqs = new List<List<int>>(n);
            int last_ans = 0;
            for (int i = 0; i < n; ++i)
                seqs.Add(new List<int>());
            for (int i = 0; i < q; ++i)
            {
                var strs = Console.ReadLine().Split(' ');
                int variant = int.Parse(strs[0]);
                int x = int.Parse(strs[1]);
                int y = int.Parse(strs[2]);
                if (variant == 1)
                    seqs[(x ^ last_ans) % n].Add(y);
                else
                {
                    var seq = seqs[(x ^ last_ans) % n];
                    last_ans = seq[y % seq.Count];
                    ans.Add(last_ans);
                }
            }
            for (int i = 0; i < ans.Count; ++i)
                Console.WriteLine(ans[i]);
        }
    }
}
