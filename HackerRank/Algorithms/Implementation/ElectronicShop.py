s, n, m = list(map(int, input().strip().split(' ')))
keyboards = list(map(int, input().strip().split(' ')))
drives = list(map(int, input().strip().split(' ')))
money = 0
for k in keyboards:
    for u in drives:
        if (k + u <= s and money < k + u):
            money = k + u
print(-1 if money == 0 else money)
