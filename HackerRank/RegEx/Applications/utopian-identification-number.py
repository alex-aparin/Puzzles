import re

for i in range(int(input())):
    print('VALID' if len(re.findall(r'^[a-z]{0,3}\d{2,8}[A-Z]{3,}$', input())) != 0 else 'INVALID')
