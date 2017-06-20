import re

for i in range(int(input())):
    print('VALID' if len(re.findall(r'^[_.]\d+[a-zA-Z]*_?$', input())) != 0 else 'INVALID')
