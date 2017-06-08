n = int(input().strip())
arr = sorted(zip(map(int, input().strip().split(' ')), range(n)), key = lambda x: x[0])
distances = [[arr[0][1]]]
for i in range(1, n):
    if arr[i - 1][0] != arr[i][0]:
        distances.append([])
    distances[-1].append(arr[i][1])
min_distance = -1
for x in distances:
    temp = sorted(x)
    if len(temp) >= 2:
        distance = abs(temp[0] - temp[1])
        if min_distance == -1:
            min_distance = distance
        else:
            min_distance = min(min_distance, distance)
print(min_distance)
