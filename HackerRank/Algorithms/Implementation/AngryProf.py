t = int(input().strip())
for a0 in range(0, t):
    n,k = map(int, input().strip().split(' '))
    a = sum(map(lambda x: 1 if int(x) <= 0 else 0, input().strip().split(' ')))
    print('YES' if a  < k else 'NO')
