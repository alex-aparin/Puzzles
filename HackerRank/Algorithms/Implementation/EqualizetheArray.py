input()
a = sorted(list(map(int, input().strip().split(' '))))
max_eq_subs, temp_eq_subs = 0, 1
for i in range(1, len(a)):
    if a[i - 1] != a[i]:
        max_eq_subs = max(max_eq_subs, temp_eq_subs)
        temp_eq_subs = 0
    temp_eq_subs += 1
max_eq_subs = max(max_eq_subs, temp_eq_subs)    
print(len(a) - max_eq_subs)
