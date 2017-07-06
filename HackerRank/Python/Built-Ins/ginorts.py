def my_key(c):
    x, offset = ord(c), 10000
    if c.islower():
        return x + offset
    if c.isupper():
        return x + offset * 2
    return int(c) + offset * (3 if int(c) % 2 != 0 else 4)
print(*sorted(input(), key=my_key), sep='')
