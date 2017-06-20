import re

s = ''
for i in range(int(input())):
    s = s + ' ' + input()
for q in range(int(input())):
    print(len(re.findall(r'\b' + input() + r'\b', s)))
