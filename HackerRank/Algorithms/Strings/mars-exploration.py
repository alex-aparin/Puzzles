s, errs = input().strip(), 0
for i in range(0, len(s), 3):
    errs += sum(map(int, [s[i] != 'S', s[i+1] != 'O', s[i+2] != 'S']))
print(errs)    
