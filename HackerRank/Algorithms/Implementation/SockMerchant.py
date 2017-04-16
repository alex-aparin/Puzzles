input()
costs, c_socks = [0] * 101, list(map(int,input().strip().split(' ')))
for i in c_socks:
    costs[i] += 1
print(sum(map(lambda x: x // 2, costs)))
