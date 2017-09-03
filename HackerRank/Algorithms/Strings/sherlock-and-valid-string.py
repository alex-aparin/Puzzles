frqs = [0] * 26
for x in input().strip():
    frqs[ord(x) - ord('a')] += 1
frqs = list(filter(lambda x: x != 0, frqs))
mn, mx, s, n = min(frqs), max(frqs), sum(frqs), len(frqs)
answer = s == n * mx or s - 1 == n * mn or s + 1 == n * mx or s - 1 == (n - 1) * mx
print('YES' if answer else 'NO')
