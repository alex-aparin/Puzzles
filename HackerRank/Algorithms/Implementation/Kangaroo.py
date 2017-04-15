def can_collide(o1, s1, o2, s2):
    s = s1 - s2
    o = o2 - o1
    if (s <= 0 or o % s != 0):
        return 'NO'
    return 'YES'

x1, v1, x2, v2 = [int(x) for x in input().strip().split(' ')]
print(can_collide(x1, v1, x2, v2))
