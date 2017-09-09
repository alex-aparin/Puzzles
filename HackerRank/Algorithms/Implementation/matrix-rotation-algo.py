import math

def lap_id(M, N, i, j):
    i = i if i < M // 2 else M - 1 - i
    j = j if j < N // 2 else N - 1 - j
    if M < N:
        i, j = j, i
    return j if j <= i else i

def to_clock(l, t, r, b, i, j):
    if i == t:
        return j - l;
    if j == r:
        return (r - l) + (i - t)
    if i == b:
        return (r - l) + (b - t) + (r - j)
    return 2 * (r - l) + (b - t) + (b - i)
    
def from_clock(l, t, r, b, c):
    if c <= r - l:
        return (t, l + c)
    c -= r - l
    if c <= b - t:
        return (t + c, r)
    c -= b - t
    if c <= r - l:
        return (b, r - c)
    c -= r - l
    return (b - c, l)

def convert(l, t, r, b, transf, i, j):
    length, clock = 2 * (r - l + b - t), to_clock(l, t, r, b, i, j)
    return from_clock(l, t, r, b, (clock + transf) % length)
  
M, N, R = map(int, input().split())
matr = [list(map(int, input().split())) for i in range(M)]
for i in range(M):
    for j in range(N):
        left, top = [lap_id(M, N, i, j)] * 2
        right, bott = N - 1 - left, M - 1 - top
        new_i, new_j = convert(left, top, right, bott, R, i, j)
        print(matr[new_i][new_j], end=' ')
    print()
