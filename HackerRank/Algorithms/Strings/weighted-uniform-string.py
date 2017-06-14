s, u, i = input().strip(), set(), 0
while i < len(s):
    c, w, temp_w = s[i], ord(s[i]) - ord('a') + 1, 0
    while i < len(s) and s[i] == c:
        temp_w, i = temp_w + w, i + 1
        u.add(temp_w)
for a0 in range(int(input().strip())):
    print('Yes' if int(input()) in u else 'No')
