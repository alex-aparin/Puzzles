d1, m1, y1 = list(map(int, input().strip().split(' ')))
d2, m2, y2 = list(map(int, input().strip().split(' ')))

ds = [y1 - y2, m1 - m2, d1 - d2]

if ds[0] < 0:
    print(0)
elif ds[0] > 0:
    print(10000)
else:
    if ds[1] < 0:
        print(0)
    elif ds[1] > 0:
        print(500 * ds[1])
    else:
        if ds[2] < 0:
            print(0)
        else:
            print(15 * ds[2])
