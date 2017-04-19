n = int(input().strip())
p, a = 0, sorted(list(map(int, input().strip().split(' '))))
buckets, sum_els = [], 0
for x in a:
    if p != x:
        buckets.append([x, 0])
        p = x
    buckets[-1][1] += 1
for i in range(0, len(buckets)):
    _mid = buckets[i][0]
    _sum_els = buckets[i][1]
    if 0 < i and buckets[i-1][0] + 1 == _mid:
        _sum_els += buckets[i-1][1]
    if sum_els < _sum_els:
        sum_els = _sum_els        
print(sum_els)
        
    
