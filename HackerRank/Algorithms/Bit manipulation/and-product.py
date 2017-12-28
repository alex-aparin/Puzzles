import math

for t in range(int(input())):
    a, b, res = map(int, (input() + " 0").split())
    for i in range(int(math.log(max(a, b), 2)), 0, -1):
        mask = 1 << i
        if (a | b) & mask != 0 and (a & b) & mask == 0:
            break
        res, i = res | (a & b) & mask, i - 1
    print(res)
