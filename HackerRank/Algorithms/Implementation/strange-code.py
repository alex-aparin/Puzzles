import math

t = int(input().strip())
geom_pos = math.floor(math.log((t - 1) / 3 + 1, 2))
print(3 * 2 ** (geom_pos + 1) - t - 2)
