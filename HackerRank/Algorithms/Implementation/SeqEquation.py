n = int(input().strip())
op_fun = [0] * (n + 1)
fun = list(map(int, input().strip().split(' ')))
for i in range(len(fun)):
    op_fun[fun[i]] = i + 1
for x in range(1, n + 1):
    print(op_fun[op_fun[x]])
