def alt_letters(s):
    cs, i = 0, 0
    while i < len(s):
        c, res_c = s[i], 0
        while i < len(s) and s[i] == c:
            i, res_c = i + 1, res_c + 1
        cs += res_c - 1
    return cs
    
for a0 in range(int(input().strip())):
    print(alt_letters(input().strip()))
