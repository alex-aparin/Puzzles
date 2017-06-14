def subs_answer(s, pattern):
    i, j = 0, 0
    while i < len(s) and j < len(pattern):
        while i < len(s) and s[i] != pattern[j]:
            i += 1
        i, j = i + 1, j + 1
    return 'YES' if j == len(pattern) else 'NO'

for a0 in range(int(input().strip())):
    print(subs_answer(input().strip(), 'hackerrank'))
