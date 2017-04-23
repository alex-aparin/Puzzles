f, n = 1, int(input().strip())
while n != 1:
    f, n = f * n, n - 1
print(f)
