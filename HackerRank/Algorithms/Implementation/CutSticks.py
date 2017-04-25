input()
a = sorted(list(map(int, input().strip().split(' '))))
while True:
    print(len(a))
    if len(a) == 0 or a[0] == a[-1]:
        break
    new_a = []
    for x in a:
        if x != a[0]:
            new_a.append(x - a[0])
    a = new_a
        
