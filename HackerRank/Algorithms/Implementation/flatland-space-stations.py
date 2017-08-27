n, m = map(int, input().strip().split())
answer, max_d, pre_m = 0, 0, None
for i in sorted([int(x) for x in input().strip().split()]):
    if pre_m == None:
        answer, pre_m = i, i
    else:
        max_d, pre_m = max(max_d, i - pre_m - 1), i
if pre_m != n - 1:
    answer = max(answer, n - pre_m - 1)
print(max(answer, max_d // 2 + max_d % 2))
