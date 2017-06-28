sts = []
for _ in range(int(input())):
    sts.append((input(), float(input())))
sts = sorted(sts, key=lambda x: x[1])
i, el = 0, sts[0][1]
while i < len(sts) and sts[i][1] == el:
    i = i + 1
el = sts[i][1]
for s in sorted(filter(lambda x : x[1] == el, sts), key = lambda x : x[0]):
    print(s[0])
