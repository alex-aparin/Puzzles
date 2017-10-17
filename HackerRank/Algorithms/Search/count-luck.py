import sys

def lucky_count(r, c, arr, luck_number, i, j):
    if arr[i][j] == '*':
        return luck_number
    arr[i][j] = 'S'
    ways_out, res = 0, 0
    for x in [(i-1, j), (i, j-1), (i+1, j), (i, j+1)]:
        if 0 <= x[0] < r and 0 <= x[1] < c:
            ways_out += arr[x[0]][x[1]] in '.*'
    for x in [(i-1, j), (i, j-1), (i+1, j), (i, j+1)]:
        if 0 <= x[0] < r and 0 <= x[1] < c and arr[x[0]][x[1]] in '.*':
            res = max(lucky_count(r, c, arr, luck_number + (ways_out > 1), *x), res)
    return res

sys.setrecursionlimit(10000)
for t in range(int(input())):
    r, c = map(int, input().split())
    arr = [['0' for j in range(c)] for i in range(r)]
    m_i, m_j = 0, 0
    for i in range(r):
        s = input()
        for j in range(c):
            arr[i][j] = s[j]
            if s[j] == 'M':
                m_i, m_j = i, j
    k = int(input())
    lucky_number = lucky_count(r, c, arr, 0, m_i, m_j)
    print("Impressed" if lucky_number == k else "Oops!")
