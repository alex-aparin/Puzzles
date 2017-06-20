import re

c = 0
for i in range(int(input())):
    c += len(re.findall(r'hackerrank', input().lower()))
print(c)   
