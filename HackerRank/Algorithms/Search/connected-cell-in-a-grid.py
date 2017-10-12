counter = 0

def fill_region(n, m, i, j, arr):
    global counter
    counter += 1
    arr[i][j] = counter
    for off_i in range(-1, 2):
        for off_j in range(-1, 2):
            i1, j1 = (i + off_i, j + off_j)
            if 0 <= i1 < n and 0 <= j1 < m and arr[i1][j1] == -1:
                fill_region(n, m, i1, j1, arr)
                
def answer(n, m, arr):
    global counter
    ans = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == -1:
                counter = 0
                fill_region(n, m, i, j, arr)
            ans = max(ans, arr[i][j])
    return ans
            
n, m = int(input()), int(input())
arr = [[-int(x) for x in input().split()] for i in range(n)]
print(answer(n, m, arr))
