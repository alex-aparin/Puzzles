input()
s = [int(x) for x in input().strip().split(' ')]
best_c, wors_c = 0, 0
min_c, max_c = s[0], s[0]
for i in range(1, len(s)):
    if s[i] > max_c:
        best_c += 1
        max_c = s[i]
    if s[i] < min_c:
        wors_c += 1
        min_c = s[i]
print (" ".join(map(str, [best_c, wors_c])))
