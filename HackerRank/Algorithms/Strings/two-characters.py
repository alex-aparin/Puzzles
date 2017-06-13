n, s = input().strip(), input().strip()
max_len, letters = 0, list(set(s))
for i in range(len(letters)):
    for j in range(i + 1, len(letters)):
        temp_len, prev_index = 0, -1
        for k in range(len(s)):
            if s[k] != letters[i] and s[k] != letters[j]:
                continue
            if prev_index == -1 or s[k] != s[prev_index]:
                prev_index, temp_len = k, temp_len + 1
            else:
                temp_len = 0
                break
        max_len = max(max_len, temp_len)
print(max_len)
