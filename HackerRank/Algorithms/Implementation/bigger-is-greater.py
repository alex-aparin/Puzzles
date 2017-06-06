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
    i = len(s) - 2
    while i >= 0:
        val_index, j = -1, len(s) - 1
        while i < j:
            if s[i] < s[j]:
                if val_index == -1 or s[val_index] < s[j]:
                    val_index = j
            j -= 1
        if i < val_index:
            chars = list(s)
            chars[i], chars[val_index] = chars[val_index], chars[i]
            return ''.join(chars)
        i -= 1
    return "no answer"
        
#   Main program
n = int(input().strip())
for i in range(0, n):
    print(answer(input().strip()))
