t = int(input().strip())
for a0 in range(t):
    res, n = 0, int(input().strip())
    temp = n
    while temp != 0:
        m = temp % 10
        temp = temp // 10
        if m != 0 and n % m == 0:
            res += 1
    print(res)
