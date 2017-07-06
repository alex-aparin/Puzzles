n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append([int(x) for x in input().split()])
k = int(input())    
for x in sorted(arr, key = lambda y: y[k]):
    print(*x)
