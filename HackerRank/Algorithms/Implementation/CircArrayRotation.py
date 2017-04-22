n, k, q = list(map(int, input().strip().split(' ')))
a = list(map(int, input().strip().split(' ')))
res = [0] * q
for i in range(q):
    res[i] = a[(int(input().strip()) - k) % len(a)]
for x in res:
    print(x)
