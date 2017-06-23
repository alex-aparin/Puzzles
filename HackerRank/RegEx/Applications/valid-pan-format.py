import re

for i in range(int(input())):
    print('YES' if len(re.findall(r'^[A-Z]{5}\d{4}[A-Z]$', input())) != 0 else 'NO')
