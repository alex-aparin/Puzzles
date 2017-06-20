import re

s = ''
for i in range(int(input())):
    s = s + ' ' + input()
# I am too lazy to see oficial specification of email    
emails = re.findall(r'(\w+(\.\w+)*[@]\w+([.][a-zA-Z]+){1,})', s)    
print(';'.join(sorted(set(map(lambda x: x[0], emails)))))
