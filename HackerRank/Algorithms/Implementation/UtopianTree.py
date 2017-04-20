cycles = [1]
for i in range(1, 61):
    cycles.append(2 * cycles[-1] if i % 2 == 1 else cycles[-1] + 1)
t = int(input().strip())
for a0 in range(0, t):
    print(cycles[int(input().strip())])
