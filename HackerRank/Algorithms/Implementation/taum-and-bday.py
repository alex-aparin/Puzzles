t = int(input().strip())
for a0 in range(t):
    b, w    = map(int, input().strip().split(' '))
    x, y, z = map(int, input().strip().split(' '))
    print(min(x, y + z) * b + min(y, x + z) * w)
