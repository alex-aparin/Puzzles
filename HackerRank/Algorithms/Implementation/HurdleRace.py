n,k = list(map(int, input().strip().split(' ')))
max_height = max(list(map(int, input().strip().split(' '))))
print(0 if max_height <= k else max_height - k)
