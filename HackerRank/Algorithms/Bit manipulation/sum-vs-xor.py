n = int(input())
print(1 if n == 0 else 2 ** (bin(n)[2:].count('0')))
