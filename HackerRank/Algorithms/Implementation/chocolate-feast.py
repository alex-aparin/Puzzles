def chocolates(n, c, m):
    chocs_count, chocs = n // c, n // c
    while chocs >= m:
        chocs_count += chocs // m
        chocs = chocs // m + chocs % m
    return chocs_count
    
for a0 in range(int(input().strip())):
    n, c, m = map(int, input().strip().split(' '))
    print(chocolates(n, c, m))
    
