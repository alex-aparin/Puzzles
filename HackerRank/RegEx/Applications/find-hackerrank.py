import re

for i in range(int(input())):
    s = input()
    if len(re.findall(r'^hackerrank(.*hackerrank)?$', s)) != 0:
        print(0)
        continue
    if len(re.findall(r'^hackerrank(?!hackerrank$)', s)) != 0:
        print(1)
        continue
    if len(re.findall(r'(?<!^hackerrank)hackerrank$', s)) != 0:
        print(2)
        continue                
    print(-1)
