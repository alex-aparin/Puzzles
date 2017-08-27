def tops(x, y):
    c = 0
    for i in range(len(x)):
        c += 1 if x[i] == '1' or y[i] == '1' else 0
    return c

n,m = map(int, input().strip().split())
max_v, max_c = 0, 0
ts = [input().strip() for i in range(n)]
for i in range(n):
    for j in range(i + 1, n):
        ts_c = tops(ts[i], ts[j])
        if max_v < ts_c:
            max_v, max_c = ts_c, 0
        if max_v == ts_c:
            max_c += 1
print(max_v, max_c, sep='\n')            
