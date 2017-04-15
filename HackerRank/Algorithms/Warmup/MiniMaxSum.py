arr = [int(x) for x in input().strip().split(' ')]
list_sum = sum(arr)
print(list_sum - max(arr), list_sum - min(arr))
