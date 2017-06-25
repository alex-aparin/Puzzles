import re

for i in range(int(input())):
    res = re.findall(r'^\(\s*([-+]?\d+([.]\d+)?)\s*[,]\s*([-+]?\d+([.]\d+)?)\s*\)$', input())
    if len(res) == 0:
        print('Invalid')
        continue
    left, right = res[0][0], res[0][2]
    if len(re.findall(r'^[-+]?0+[1-9]',left)) != 0 or len(re.findall(r'^[-+]?0+[1-9]',right)) != 0:
        print('Invalid')
        continue
    left, right = float(left), float(right)
    if -90.0 <= left <= 90.0 and -180.0 <= right <= 180.0:
        print('Valid')
        continue
    print('Invalid')
