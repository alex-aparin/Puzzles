for t in range(int(input())):
    input()
    a = set(input().split())
    input()
    b = set(input().split())
    print(len(a & b) == len(a))
