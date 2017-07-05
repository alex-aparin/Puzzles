n, x = [int(i) for i in input().split()]
scores = []
for i in range(x):
    scores.append(map(float, input().split()))
for i in zip(*scores):
    print(sum(i) / x)
