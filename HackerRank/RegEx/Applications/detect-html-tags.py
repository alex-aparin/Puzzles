import re

s = ''
for _ in range(int(input())):
    s = s + input()
unique_tags = ';'.join(sorted(set(re.findall(r'<(\w+).*?>', s))))
print(unique_tags)
