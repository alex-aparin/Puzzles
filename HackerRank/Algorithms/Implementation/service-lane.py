import math
n, t = map(int, input().strip().split())
st = [[4] * n for row in range(math.ceil(math.log(n, 2)) + 1)]
st[0] = [int(x) for x in input().strip().split()]
for k in range(1, len(st)):
    for i in range(n - (2 ** k - 1)):
        st[k][i] = min(st[k-1][i], st[k-1][i + 2 ** (k-1)])
for test in range(t):
    i, j = map(int, input().strip().split())
    k = int(math.log(j - i + 1, 2))
    print(min(st[k][i], st[k][j - 2 ** k + 1]))
