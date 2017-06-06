def answer(s):
    i = len(s) - 2
    while i >= 0:
        val_index, j = -1, len(s) - 1
        while i < j:
            if s[i] < s[j]:
                if val_index == -1 or s[j] < s[val_index]:
                    val_index = j
            j -= 1
        if i < val_index:
            chars = list(s)
            chars[i], chars[val_index] = chars[val_index], chars[i]
            return ''.join(chars[:i+1] + sorted(chars[i+1:]))
        i -= 1
    return "no answer"
        
#   Main program
n = int(input().strip())
for i in range(0, n):
    print(answer(input().strip()))
