n, k = list(map(int, input().strip().split(' ')))
c, e, pos = list(map(int,  input().strip().split(' '))), 100, 0
while True:
    pos = (pos + k) % n
    e -= 1 + c[pos] * 2
    if pos == 0:
        break
print(e)        
