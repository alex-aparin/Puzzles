import re

def is_valid_ipv4(s):
    res = re.findall(r'^(\d+)[.](\d+)[.](\d+)[.](\d+)$', s)
    if res == []:
        return False
    t = list(map(lambda x: 0 <= x <= 255, map(int, list(res[0]))))
    return not (False in list(t))

def is_valid_ipv6(s):
    res = re.findall(r'^([0-9a-f]{1,4}:){7}[0-9a-f]{1,4}$', s)
    return res != []

for i in range(int(input())):
    s = input()
    if is_valid_ipv4(s):
        print('IPv4')
        continue
    if is_valid_ipv6(s):
        print('IPv6')
        continue
    print('Neither')        
