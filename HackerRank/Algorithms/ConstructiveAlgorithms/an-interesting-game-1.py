for q in range(int(input())):
    n, is_bob = int(input()), True
    a = sorted(zip(map(int, input().split()), range(n + 1)), key = lambda x: x[0])
    n, prev_fpos = n - 1, a[-1][1]
    while 0 <= n:
        if a[n][1] < prev_fpos:
            prev_fpos, is_bob = a[n][1], not is_bob
        n -= 1
    print('BOB' if is_bob else 'ANDY')
