for t in range(int(input())):
    m, n, d = int(input()), int(input()), {}
    for i, c in enumerate(map(int, input().split()), 1):
        if m - c in d:
            print(d[m - c], i)
            break
        d[c] = i
