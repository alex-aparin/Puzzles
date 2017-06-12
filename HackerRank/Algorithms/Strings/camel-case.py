s, words = input().strip(), 1
for x in s:
    words += 1 if x.isupper() else 0
print(words)
