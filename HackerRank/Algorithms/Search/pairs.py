def pairs(a, k):
    s = set(a)
    return sum(map(lambda x: x + k in s, a))
