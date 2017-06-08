def is_sink(grid_map, i, j):
    val = ord(grid_map[i][j]) - ord('0')
    for off in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
        if ord(grid_map[i - off[1]][j + off[0]]) - ord('0') >= val:
            return False
    return True

n = int(input().strip())
grid_map = ['9' * (n + 2)]
for i in range(n):
   grid_map.append('9' + input().strip() + '9')
grid_map.append('9' * (n + 2))
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if is_sink(grid_map, i, j):
            print('X', end='')
        else:
            print(grid_map[i][j], end='')
    print('')
