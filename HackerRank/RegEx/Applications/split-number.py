import re

for i in range(int(input())):
    res = re.findall(r'(\d+)([-\s])(\d+)\2(\d+)', input())
    res = ['CountryCode='   + res[0][0], 
           'LocalAreaCode=' + res[0][2],
           'Number='        + res[0][3]]
    print(','.join(res))
