def reverse_num(x):
    num = 0
    while x != 0:
        num, x = num * 10 + x % 10, x // 10
    return num

i, j, k = list(map(int, input().strip().split(' ')))
print(sum(map(lambda x: 1 if (x - reverse_num(x)) % k == 0 else 0, range(i, j + 1))))
