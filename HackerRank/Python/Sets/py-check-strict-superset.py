a, is_strict = set(input().split()), True
for i in range(int(input())):
    s = set(input().split())
    is_strict = is_strict and len(a & s) == len(s) and len(a) > len(s)
print(is_strict)    
