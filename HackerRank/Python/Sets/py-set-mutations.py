input()
a = set(input().split())
d = {'update' : lambda x, y: x | y, 
     'intersection_update' : lambda x, y: x & y, 
     'difference_update' : lambda x, y: x -y,
     'symmetric_difference_update' : lambda x, y: x ^ y}
for i in range(int(input())):
    q = input().split()[0]
    a = d[q](*[a, set(input().split())])
print(sum(map(int, a)))    
