def an_changes(s):
    if len(s) % 2 != 0:
        return -1
    balances = [0] * 26
    for i in range(len(s)):
        balances[ord(s[i]) - ord('a')] += 1 if i < len(s) // 2 else -1
    return sum(map(abs, balances)) // 2

for i in range(int(input().strip())):
    print(an_changes(input().strip()))
