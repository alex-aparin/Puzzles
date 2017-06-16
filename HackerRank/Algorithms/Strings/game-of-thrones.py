import collections

odd_count = 0
for c, fr in collections.Counter(input().strip()).items():
    odd_count += fr % 2
print('YES' if odd_count <= 1 else 'NO')
