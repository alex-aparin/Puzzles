import functools
input()
print(functools.reduce(lambda x, y: x ^ y, map(int, input().strip().split(' ')), 0))
