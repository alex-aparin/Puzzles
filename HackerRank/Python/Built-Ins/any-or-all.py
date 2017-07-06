def is_palind(n):
    n = str(n)
    return n[:len(n) // 2 + 1] == n[::-1][:len(n) // 2 + 1]
input()
arr = [int(x) for x in input().split()]
print(all(map(lambda x: x>0, arr)) and any(map(is_palind, arr)))
