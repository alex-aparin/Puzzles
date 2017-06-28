input()
arr = list(map(int, input().split()))
max_el = max(arr)
print(max(filter(lambda x : x != max_el, arr)))
