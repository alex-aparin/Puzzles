def mins(pos, cend, cs):
    if pos == cend:
        return 0
    if pos > cend or cs[pos] == 1:
        return -1 * (cend + 1)
    res = mins(pos + 2, cend, cs)
    if res >= 0:
        return 1 + res
    else:
        return 1 + mins(pos + 1, cend, cs)
n = int(input().strip())
c = list(map(int, input().strip().split(' ')))
print(mins(0, n - 1, c))
