n, s = int(input()), set(map(int, input().split())) 
d = {'pop' : lambda x: x.pop(), 
     'remove' : lambda x, n: x.remove(int(n)), 
     'discard' : lambda x, n: x.discard(int(n))}
for i in range(int(input())):
    q = input().split()
    d[q[0]](*[s] + q[1:])
print(sum(s))
