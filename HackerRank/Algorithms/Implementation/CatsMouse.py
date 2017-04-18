q = int(input().strip())
for a0 in range(q):
    x,y,z = list(map(int, input().strip().split(' ')))
    x, y = abs(x - z), abs(y - z)
    if x == y:
        print('Mouse C')
    elif x < y:
        print('Cat A')
    else:
        print('Cat B')
