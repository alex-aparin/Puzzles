s, t, k = input().strip(), input().strip(), int(input().strip())
occur = 0
while occur < len(t) and occur < len(s) and s[occur] == t[occur]:
    occur += 1
if (k >= len(s) + len(t)):
    print("Yes")
else:
    k = k - (abs(len(s) - occur) + len(t) - occur)
    if k >= 0 and k % 2 == 0:
        print("Yes")
    else:
        print("No")
