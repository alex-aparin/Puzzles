def theLoveLetterMystery(s):
    ans = 0
    for i in range(0, len(s) // 2):
        ans += abs(ord(s[i]) - ord(s[-1-i]))
    return ans                   
        
for i in range(int(input().strip())):
    print(theLoveLetterMystery(input().strip()))
