def pal_traverse(i, j,  s):
    while i <= j and s[i] == s[j]:
        i, j = i + 1, j - 1
    return (i, j)
def pal_index(s):
    index, (i, j) = -1, pal_traverse(0, len(s) - 1, s)
    if i > j:
        return index
    index, (i, j) = i, pal_traverse(i + 1, j, s)
    if i > j:
        return index
    index, (i, j) = len(s) - 1 - index,  pal_traverse(index, len(s) - 2 - index, s)
    return index if i > j else -2
    
for t in range(int(input())):
    print(pal_index(input()))
