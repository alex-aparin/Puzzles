def answer(ar):
    s_ar, ids = sorted(ar), []
    if ar == s_ar:
        return 'yes'
    for i, (x, y) in enumerate(zip(ar, s_ar)):
        if x != y:
            ids.append(i)    
    #   swapping
    ar[ids[0]], ar[ids[-1]] = ar[ids[-1]], ar[ids[0]]
    if ar == s_ar:
        return 'yes\nswap {0} {1}'.format(ids[0] + 1, ids[-1] + 1)
    ar[ids[0]], ar[ids[-1]] = ar[ids[-1]], ar[ids[0]]
    #   reversing
    ar[ids[0]:ids[-1] + 1] = ar[ids[0]:ids[-1]+1][::-1]
    if ar == s_ar:
        return 'yes\nreverse {0} {1}'.format(ids[0] + 1, ids[-1] + 1)
    return 'no'
    
input()
print(answer([int(x) for x in input().split()]))
