n, studs = int(input()), {}
for _ in range(n):
    name, *marks = input().split()
    studs[name] = sum(map(float, marks)) / 3
print('{:.2f}'.format(studs[input()]))
