n, s, min_s = int(input().strip()), list(input().strip()), 0
for i in range(0, len(s) - 2):
    if s[i] == '0' and s[i+1] == '1' and s[i+2] == '0':
        s[i+2], min_s = '1', min_s + 1
print(min_s)
