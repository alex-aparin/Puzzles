import re

s = ''
for n in range(int(input())):
    s = s + ' ' + input()
for t in range(int(input())):
    print(len(re.findall(r'\b' + input().replace('our', 'ou?r') + r'\b', s)))
    
    
