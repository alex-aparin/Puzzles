def merge(a):
    i = 0
    while i + 1 < len(a):
        if a[i + 1][0] <= a[i][1]:
            a[i] = (a[i][0], max(a[i][1], a[i + 1][1]))
            del a[i+1]
            continue
        i = i + 1
    return a

trs = []
r, c, k = map(int, input().split())
for i in range(k):
    ri, ci1, ci2 = [int(x) - 1 for x in input().split()]
    trs.append((ri * c + ci1, ri * c + ci2))
print(r * c  - sum(map(lambda x: x[1] - x[0] + 1, merge(sorted(trs, key = lambda x: x[0])))))
