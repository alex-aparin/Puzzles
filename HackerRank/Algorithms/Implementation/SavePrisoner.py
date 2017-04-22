t = int(input().strip())
for i in range(0, t):
    n, m, s = list(map(int, input().strip().split(' ')))
    print((s - 1 + m - 1) % n + 1)
