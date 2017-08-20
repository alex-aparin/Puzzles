input()
b, loaves= list(map(int, input().strip().split())) + [0], 0
for i in range(len(b) - 1):
    if b[i] & 1 == 0:
        continue
    b[i], loaves = b[i] + 1, loaves + 1
    if i + 1 < len(b):
        b[i + 1], loaves = b[i + 1] + 1, loaves + 1
print(loaves if all(map(lambda x: x & 1 == 0, b)) else 'NO')
