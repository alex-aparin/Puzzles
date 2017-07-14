for t in range(int(input())):
    n, a, b = map(int, (input() + ' ' + input() + ' ' + input()).split())
    res = []
    for i in range(n):
        res.append(i * a + (n - i - 1) * b)
    print(*sorted(set(res)))
