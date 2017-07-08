from itertools import *
s, k = input().split()
for i in range(1, int(k) + 1):
    for x in sorted(map(sorted, combinations(s, i))):
        print(''.join(x))
