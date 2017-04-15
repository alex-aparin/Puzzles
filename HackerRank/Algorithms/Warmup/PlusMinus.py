n = int(input().strip())
arr = [int(x) for x in input().strip().split(' ')]
print("{0:.6f}".format(len([x for x in arr if x > 0]) / n))
print("{0:.6f}".format(len([x for x in arr if x < 0]) / n))
print("{0:.6f}".format(len([x for x in arr if x == 0]) / n))
