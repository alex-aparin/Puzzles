a, b = int(input()), int(input())
if a < b:
    a, b = b, a
a, b = list(format(a, 'b')), list(format(b, 'b'))
b = ['0'] * (len(a) - len(b)) + b
i = 0
while i < len(a):
    if a[i] == b[i] == '1':
        a[i] = '0'
        i += 1
        continue
    if a[i] == '1' and b[i] == '0':
        while i < len(a):
            a[i] = '1'
            i += 1
    i += 1
print(int("".join(a), 2))
