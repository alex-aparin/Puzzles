n, k = list(map(int, input().strip().split(' ')))
c, b = list(map(int, input().strip().split(' '))), int(input())
actual = (sum(c) - c[k]) // 2
if actual == b:
    print('Bon Appetit')
else:
    print(b - actual)
