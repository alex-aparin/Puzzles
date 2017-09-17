def end_sorted(ar):
    return ar[-3] <= ar[-2] <= ar[-1]
def shift(ar, i):
    ar[i-1:i+2] = [ar[i], ar[i+1], ar[i-1]]
def shift_sort(ar):
    i, n = 0, len(ar)
    while i + 3 < n:
        rots = ar.index(i+1) - i
        if i + rots == n - 1:
            shift(ar, i + rots - 1)
            rots -= 1
        while rots > 0:
            shift(ar, i + rots)
            rots -= 1
        i += 1
def sol(ar):
    shift_sort(ar)
    if end_sorted(ar):
        return 'YES'
    shift(ar, len(ar) - 2)
    if end_sorted(ar):
        return 'YES'
    shift(ar, len(ar) - 2)
    return 'YES' if end_sorted(ar) else 'NO'
for t in range(int(input())):
    temp, ar = input(), list(map(int, input().split()))
    print(sol(ar))
