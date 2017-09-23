n, a = int(input()), sorted([int(x) for x in input().split()])
m, b = int(input()), sorted([int(x) for x in input().split()])
i, j, last = 0, 0, None
while i < n and j < m:
    if a[i] == b[j]:
        i, j = i + 1, j + 1
        continue
    if last != b[j]:
        print(b[j], end=' ')
    last, j = b[j], j + 1
while j < m:
    if last != b[j]:
        print(b[j], end=' ')
    last, j = b[j], j + 1
