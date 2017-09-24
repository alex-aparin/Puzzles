def put_radio(n, k, xs, i):
    j = i
    while j < n and xs[j] - xs[i] <= k:
        j = j + 1
    i = j - 1
    while j < n and xs[j] - xs[i] <= k:
        j = j + 1
    return j
    
n, k = map(int, input().split())
xs, rds, i = sorted([int(x) for x in input().split()]), 0, 0
while i < n:
    rds, i = rds + 1, put_radio(n, k, xs, i)
print(rds)
    
