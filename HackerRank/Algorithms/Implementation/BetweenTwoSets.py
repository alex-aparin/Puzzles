def find_divs(x):
    divs, i = [], 1
    for i in range(1, x + 1):
        if (x % i == 0):
            divs.append(i)
    return divs

m, n = [int(x) for x in input().strip().split(' ')]
a    = [int(x) for x in input().strip().split(' ')]
b    = [int(x) for x in input().strip().split(' ')]
ans = []
for x in find_divs(min(b)):
    a_c, b_c = 0, 0
    for ai in a:
        if (x % ai == 0):
            a_c = a_c + 1
    for bi in b:
        if (bi % x == 0):
            b_c = b_c + 1
    if (a_c == m and b_c == n):
        ans.append(x)
print(len(ans))
