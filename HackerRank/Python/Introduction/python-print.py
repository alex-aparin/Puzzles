def to_str(i):
    s = ''
    while True:
        s = chr(ord('0') + i % 10) + s
        i = i // 10
        if i == 0:
            break
    return s
            
for i in range(1, int(input()) + 1):
    print(to_str(i), end='')
