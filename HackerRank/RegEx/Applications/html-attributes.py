import re
s = ''
for i in range(int(input())):
    s = s + ' ' + input()
res, tags = re.findall(r'<(\w+)(.*?)>', s), {}
for t in res:
    if not t[0] in tags:
        tags[t[0]] = []
    tags[t[0]].extend(re.findall(r'(\w+)=["\']', t[1]))  
for t, att in sorted(tags.items()):
    print(t + ':' + ','.join(sorted(set(att))))
