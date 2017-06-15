def funnyString(s):
    funny, n = True, len(s)
    for i in range(1, n):
        left = abs(ord(s[i]) - ord(s[i-1]))
        right = abs(ord(s[n-i]) - ord(s[n-i-1]))
        funny = funny and left == right
    return 'Funny' if funny else 'Not Funny'

for a0 in range(int(input().strip())):
    print(funnyString(input().strip()))
