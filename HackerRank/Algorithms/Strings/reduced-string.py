s, ls = input().strip(), []
for x in s:
    if len(ls) == 0 or ls[-1] != x:
        ls.append(x)
        continue
    ls.pop()
if len(ls) == 0:
    print('Empty String')
else:
    print(''.join(ls))

