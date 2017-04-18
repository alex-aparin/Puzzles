input()
hikes = list(map(lambda x: -1 if x == 'D' else 1, input().strip()))
s, res = 0, 0
for i in hikes:
    s += i
    if s == 0 and i == 1:
        res += 1
print(res)
