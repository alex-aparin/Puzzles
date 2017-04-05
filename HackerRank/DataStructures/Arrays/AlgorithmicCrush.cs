using System;
using System.Collections.Generic;

namespace HackerRank
{
    class Solution
    {
        class Node
        {
            public Node(Node p, long a, long b)
            {
                Parent = p;
                A = a;
                B = b;
            }

            static public Node create_tree(long a, long b, Node parent = null)
            {
                if (a > b)
                    return null;
                var root = new Node(parent, a, b);
                if (a != b)
                {
                    root.Left = create_tree(a, (a + b) / 2, root);
                    root.Right = create_tree((a + b) / 2 + 1, b, root);
                }
                return root;
            }

            public long add_num(long a, long b, long k)
            {
                if (A == a && B == b)
                {
                    SumEl = SumEl + k;
                    return Max + SumEl;
                }
                if (Left != null && a <= Left.B)
                {
                    Max = Math.Max(Max, Left.add_num(a, Math.Min(b, Left.B), k));
                }
                if (Right != null && Right.A <= b)
                {
                    Max = Math.Max(Max, Right.add_num(Math.Max(a, Right.A), b, k));
                }
                return Max + SumEl;
            }
            public long A       { get; }
            public long B       { get; }
            public Node Parent { get; }
            public Node Left   { get; set; }
            public Node Right  { get; set; }
            public long Max     { get; set; }
            public long SumEl   { get; set; }
        }

        static void Main(string[] args)
        {
            var strs = Console.ReadLine().Split(' ');
            long n = long.Parse(strs[0]);
            long m = long.Parse(strs[1]);
            var root = Node.create_tree(1, n);
            long max_element = 0;
            for (long i = 0; i < m; ++i)
            {
                var temps = Console.ReadLine().Split(' ');
                max_element = root.add_num(long.Parse(temps[0]), 
                    long.Parse(temps[1]), long.Parse(temps[2]));
            }
            Console.WriteLine(max_element);
        }
    }
}
