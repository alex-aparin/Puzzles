input()
arr, happiness = [int(x) for x in input().split()], 0
a = set([int(x) for x in input().split()])
b = set([int(x) for x in input().split()])
for x in arr:
    if x in a:
        happiness += 1
    elif x in b:
        happiness -= 1
print(happiness)  
