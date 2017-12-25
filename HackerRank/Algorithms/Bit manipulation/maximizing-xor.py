import math
res = (1 << math.floor(math.log(int(input()) ^ int(input()), 2) + 1)) - 1
print(res)
