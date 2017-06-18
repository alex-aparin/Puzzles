import re

for _ in range(int(input())):
    for link, title in re.findall(r'<a href="(.*?)".*?>([\w ,./]*)(?=</)', input()):
        print("{},{}".format(link, title.strip()))
