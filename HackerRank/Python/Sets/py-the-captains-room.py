k = int(input())
rooms = [int(x) for x in input().split()]
cap_k_1 = sum(set(rooms)) * k - sum(rooms)
print(cap_k_1 // (k - 1))
