n, k = map(int, input().strip().split(' '))
ts, spec_tasks, page = map(int, input().strip().split(' ')), 0, 1
for t in ts:
    current_t = 1
    while current_t <= t:
        if current_t <= page < min(current_t + k, t + 1):
            spec_tasks += 1
        current_t += k
        page += 1
print(spec_tasks)        
