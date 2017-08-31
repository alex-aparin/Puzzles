from math import *

n, k = map(int, input().strip().split())
rq, cq = map(int, input().strip().split())
ds = {}
ds[0], ds[90], ds[180], ds[270] = cq - 1, rq - 1, n - cq, n - rq
for st_angle in [0, 90, 180, 270]:
    ds[st_angle + 45] = min(ds[st_angle], ds[(st_angle + 90) % 360])
for t in range(k):
    ro, co = map(int, input().strip().split())
    dx, dy = co - cq, ro - rq
    if dx == 0 or dy == 0 or abs(dx) == abs(dy):
        phi = int((atan2(dy, dx) + pi) * 180.0 / pi) % 360
        d = (max if phi % 90 == 0 else min)(abs(dx), abs(dy))
        ds[phi] = min(ds[phi], d - 1)
print(sum(ds.values()))
