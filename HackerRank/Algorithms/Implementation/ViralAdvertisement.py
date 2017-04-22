n, m, res = int(input().strip()), 5, 0
for i in range(0, n):
    m = m // 2
    res += m
    m = m * 3
print(res)
