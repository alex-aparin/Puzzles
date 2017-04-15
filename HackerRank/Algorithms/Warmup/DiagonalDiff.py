n, res = int(input().strip()), 0
for i in range(n):
    a_i = [int(x) for x in input().strip().split(' ')]
    res += a_i[i] - a_i[n - 1 - i]
print(abs(res))
