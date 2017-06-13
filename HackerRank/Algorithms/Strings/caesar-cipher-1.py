def CaesarMapper(x, k):
    if 'a' <= x <= 'z':
        return chr((ord(x) - ord('a') + k) % 26 + ord('a'))
    if 'A' <= x <= 'Z':
        return chr((ord(x) - ord('A') + k) % 26 + ord('A'))
    return x

n, s, k = int(input().strip()), input().strip(), int(input().strip())
print(''.join(map(lambda x: CaesarMapper(x, k), s)))
