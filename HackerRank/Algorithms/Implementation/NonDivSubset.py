n, k = list(map(int, input().strip().split(' ')))
a = list(map(int, input().strip().split(' ')))
mods = [0] * k
for i in range(n):
    mods[a[i] % k] += 1
res = 1 if mods[0] != 0 else 0
if k % 2 == 0:
    mods[k // 2] = 1 if mods[k // 2] != 0 else 0
for i in range(1, k // 2 + 1):
    res += max(mods[-i], mods[i])
print(res)
