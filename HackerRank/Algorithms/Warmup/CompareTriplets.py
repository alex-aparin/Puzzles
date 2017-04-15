ai = [int(x) for x in input().strip().split(' ')]
bi = [int(x) for x in input().strip().split(' ')]
alice, bob = 0, 0
for a, b in zip(ai, bi):
    if a > b:
        alice += 1
    elif a < b:
        bob += 1
print(alice, bob)
