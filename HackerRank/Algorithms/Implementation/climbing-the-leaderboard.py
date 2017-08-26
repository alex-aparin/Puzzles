def rank(s, scores):
    i, j = 0, len(scores) - 1
    while i < j:
        k = (i + j) // 2
        i, j = (k+1, j) if scores[k] > s else (i, k-1)
    return i + 1 + (scores[i] > s)

input()
scores = sorted(list(set([int(s) for s in input().strip().split()])), reverse=True)
input()
for s in map(int, input().strip().split()):
    print(rank(s, scores))
