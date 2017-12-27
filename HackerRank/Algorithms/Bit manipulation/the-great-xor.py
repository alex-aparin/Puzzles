for t in range(int(input().strip())):
    res, n = 0, format(int(input().strip()), 'b')
    for i in range(len(n)):
        if n[i] == '0':
            res += 2 ** (len(n) - 1 - i)
    print(res)
