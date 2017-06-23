import re

s = ''
for i in range(int(input())):
    s = s + ' ' + input()
for i in range(int(input())):
    q = input()
    print(len(re.findall(r'\b(' + q + '|' + q[:-2]+ r'se\b)', s)))
