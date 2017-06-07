import math

s = input().strip()
d = len(s)
rows, cols = math.floor(math.sqrt(d)), math.ceil(math.sqrt(d))
if rows * cols < d:
    if rows < cols:
        rows += 1
    else:
        cols += 1
for j in range(0, cols):
    for i in range(0, rows):
        index = i * cols + j
        if index >= d:
            break
        print(s[index], end = '')        
    print(' ', end = '')
