import copy

n, d = map(int, input().strip().split(' '))
seq = map(int, input().strip().split(' '))

set_els, triples_count = set(copy.deepcopy(seq)), 0
for x in seq:
    if x + d in set_els and x + 2 * d in set_els:
        triples_count += 1
print(triples_count)        
