import collections, itertools

for game_id in range(int(input().strip())):
    n, b, res = int(input().strip()), input().strip(), False
    if '_' in b:
        counter = collections.Counter(b)
        res = all(map(lambda x: x[0] == '_' or x[1] > 1, counter.items()))
    else:
        res = all(map(lambda x: len(list(x[1])) > 1, itertools.groupby(b)))
    print('YES' if res else 'NO')
