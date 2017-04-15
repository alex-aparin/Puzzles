res, n = 0, int(input())
bar = [int(x) for x in input().strip().split(' ')]
d, m = [int(x) for x in input().strip().split(' ')]
if m <= n:
    prev, p = 0, sum(bar[:m]) - bar[m-1]
    for i in range(m - 1, n):
        p -= prev
        prev = bar[i - m + 1]
        p += bar[i]
        res += 1 if p == d else 0
print(res)
