using System;
using System.Text;
using System.Collections.Generic;

public class Program
{
    private enum TokenType
    {
        Variable,
        Operation
    }
    private struct CustomOperator
    {
        public CustomOperator(string _id, int _prior, bool _left_assoc)
        {
            id = _id;
            prior = _prior;
            left_assoc = _left_assoc;
        }
        public readonly string id;
        public readonly int prior;
        public readonly bool left_assoc;
    }
    static Dictionary<string, CustomOperator> operators = new Dictionary<string, CustomOperator>()
    {
        ["("] = new CustomOperator("(", 0, true),
        [")"] = new CustomOperator(")", 0, true),
        ["-"] = new CustomOperator("-", 1, true),
        ["+"] = new CustomOperator("+", 1, true),
        ["*"] = new CustomOperator("*", 2, true),
        ["/"] = new CustomOperator("/", 2, true),
        ["^"] = new CustomOperator("^", 3, true),
    };
    static string get_token(string str, ref int index)
    {
        return new string(str[index++], 1);
    }
    static TokenType token_type(string token)
    {
        if (token.Length == 1 && 'a' <= token[0] && token[0] <= 'z')
            return TokenType.Variable;
        if (operators.ContainsKey(token))
            return TokenType.Operation;
        throw new Exception($"Unrecognized token {token}");
    }
    static string decode_to_rpn(string str)
    {
        var ops = new LinkedList<CustomOperator>();
        var builder = new StringBuilder(str.Length);
        for (int index = 0; index < str.Length; )
        {
            string token = get_token(str, ref index);
            switch (token_type(token))
            {
                case TokenType.Variable:
                    builder.Append(token);
                    break;
                case TokenType.Operation:
                    var op = operators[token];
                    if (ops.Count == 0 || op.id[0] == '(')
                        ops.AddLast(op);
                    else if (op.id[0] == ')')
                    {
                        while (ops.Last.Value.id[0] != '(')
                        {
                            builder.Append(ops.Last.Value.id);
                            ops.RemoveLast();
                        }
                        ops.RemoveLast();
                    }
                    else
                    {
                        while (op.left_assoc == false && op.prior < ops.Last.Value.prior)
                        {
                            builder.Append(ops.Last.Value.id);
                            ops.RemoveLast();
                        }
                        while (op.left_assoc == true && op.prior <= ops.Last.Value.prior)
                        {
                            builder.Append(ops.Last.Value.id);
                            ops.RemoveLast();
                        }
                        ops.AddLast(op);
                    }
                    break;
            }
        }
        while (ops.Count != 0)
        {
            builder.Append(ops.Last.Value.id);
            ops.RemoveLast();
        }
        return builder.ToString();
    }
    static public void Main()
    {
        var n = Convert.ToInt32(Console.ReadLine());
        var strs = new List<string>(n);
        for (int i = 0; i < n; ++i)
            strs.Add(Console.ReadLine());
        for (int i = 0; i < n; ++i)
            Console.WriteLine(decode_to_rpn(strs[i]));
    }
}
