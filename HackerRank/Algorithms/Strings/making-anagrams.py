occs, s1, s2 = [0] * 26, input().strip(), input().strip()
for i, c in enumerate(s1 + s2):
    occs[ord(c) - ord('a')] += 1 if i < len(s1) else -1
print(sum(map(abs, occs)))
