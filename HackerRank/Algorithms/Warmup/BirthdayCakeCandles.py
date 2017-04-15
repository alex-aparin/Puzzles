input()
candles = [int(x) for x in input().strip().split(' ')]
print(candles.count(max(candles)))
