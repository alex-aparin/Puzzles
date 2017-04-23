for t in range(int(input())):
    a, b = list(map(int, input().strip().split(' ')))
    l = int(a ** 0.5)
    l = l if l ** 2 == a else l + 1
    r = int(b ** 0.5)
    print(r - l + 1)
