def ans(a):
    left, right = 0, sum(a)
    for x in a:
        right = right - x
        if left == right:
            return 'YES'
        left = left + x
    return 'NO'

for t in range(int(input())):
    input()
    print(ans([int(x) for x in input().split()]))
