import sys, re

s = ''
for t in sys.stdin:
    s = s + ' ' + t
ans = re.findall(r'(href="/questions/(\d+)/.*?>(.*?)<|relativetime">(.*?)<)', s)
for i in range(0, len(ans), 2):
    print(';'.join(list(ans[i][1:3])+[ans[i+1][3]]))
