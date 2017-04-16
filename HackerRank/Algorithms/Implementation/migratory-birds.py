n, birds, t_counts = int(input()), list(map(int, input().strip().split(' '))), [0] * 6
for x in birds:
    t_counts[x] += 1
print(t_counts.index(max(t_counts)))
