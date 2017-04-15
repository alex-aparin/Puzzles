s,t = [int(x) for x in input().strip().split(' ')]
a,b = [int(x) for x in input().strip().split(' ')]
m,n = [int(x) for x in input().strip().split(' ')]
apple  = sum([1 if s <= a + int(x) <= t else 0 for x in input().strip().split(' ')])
orange = sum([1 if s <= b + int(x) <= t else 0 for x in input().strip().split(' ')])
print(apple)
print(orange)
