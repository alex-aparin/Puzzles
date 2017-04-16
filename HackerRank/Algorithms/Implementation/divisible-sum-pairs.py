n, k = [int(x) for x in input().strip().split(' ')]
a, mods= [int(x) for x in input().strip().split(' ')], [0] * (k + 1)
for x in a:
    mods[x % k] += 1
res = (mods[0] - 1) * mods[0] // 2
if (k % 2 == 0):
    res += (mods[k // 2] - 1) * mods[k // 2] // 2
for i in range(1, k // 2 + k % 2):
    res += mods[i] * mods[k - i]
print(res)
