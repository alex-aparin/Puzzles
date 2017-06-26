import re, sys

com_opened = False
for s in sys.stdin:
    res = re.findall(r'(//|/[*]|[*]/)', s)
    if res == []:
        if com_opened:
            print(s[:len(s)-1].lstrip())
        continue
    com_opened = res[-1] == '/*'
    print(re.findall(r'(//.*|/[*].*?[*]/|/[*].*|.*?[*]/)', s)[0].lstrip())
