def pal_diffs(ar):
    i, j, ds = 0, len(ar) - 1, 0
    while i <= j:
        ds, i, j = ds + (ar[i] != ar[j]), i + 1, j - 1
    return ds    
def richie_rich(ar, k):
    i, j, ds = 0, len(ar) - 1, k - pal_diffs(ar)
    if ds < 0:
        return '-1'
    while i <= j:
        if ar[i] != ar[j]:
            ar[i], ar[j] = [max(ar[i], ar[j])] * 2
            if ar[i] != 9 and ds >= 1:
                ar[i], ar[j], ds = 9, 9, ds - 1
        else:
            if ar[i] != 9 and i != j and ds >= 2:
                ar[i], ar[j], ds = 9, 9, ds - 2
            if ar[i] != 9 and i == j and ds >= 1:
                ar[i], ar[j], ds = 9, 9, ds - 1
        i, j = i + 1, j - 1
    return ''.join(map(str, ar))
n, k = map(int, input().split())
print(richie_rich(list(map(int, input())), k))
