ops = {'insert' : lambda l, i, e: l.insert(i, e),
       'print'  : lambda l : print(l),
       'remove' : lambda l, e : l.remove(e),
       'append' : lambda l, e : l.append(e),
       'sort'   : lambda l : l.sort(),
       'pop'    : lambda l : l.pop(),
       'reverse': lambda l : l.reverse()
      }
base_list = []
for i in range(int(input())):
    q = input().strip().split()
    ops[q[0]](*[base_list] + list(map(int, q[1:])))
