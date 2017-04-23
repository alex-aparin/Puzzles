s = input().strip()
n = int(input().strip())
full, sub, s_mod = 0, 0, n % len(s)
for i in range(len(s)):
    if s[i] == 'a':
        full += 1
        if i < s_mod:
            sub += 1
print((n // len(s)) * full + sub)            
