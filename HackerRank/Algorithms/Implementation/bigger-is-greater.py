#   Aux funcs
def has_greater_str(s):
    c = s[0]
    for x in s[1:]:
        if c < x:
            return True
        c = x
    return False

def answer(s):
    if has_greater_str(s) == False:
        return "no answer"
    return "no answer"
    i = len(s) - 2
    while i >= 0:
        
    for i in range(0, len(s)):
        
#   Main program
n = int(input().strip())
for i in range(0, n):
    print(answer(input().strip()))
