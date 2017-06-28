res = [False] * 5
for s in input():
    res[0] = res[0] or s.isalnum()
    res[1] = res[1] or s.isalpha()
    res[2] = res[2] or s.isdigit()
    res[3] = res[3] or s.islower()
    res[4] = res[4] or s.isupper()
for x in res:
    print(x)
