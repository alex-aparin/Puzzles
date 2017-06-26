import re

res, pattern = set(), re.compile(r'https?://(www[.])?(.*?)[\\/?"\'_ ]')
for i in range(int(input())):
    for x in pattern.findall(input()):
        if '.' in x[1]:
            res.add(x[1])
print(';'.join(sorted(res)))
    
    
