import re

for i in range(int(input())):
    s = input()
    if len(re.findall(r'^[Hh][Ii]\s[^Dd]', s)) != 0:
        print(s)
