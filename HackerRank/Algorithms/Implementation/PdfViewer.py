heights = map(int, input().strip().split(' '))
h = dict(zip(map(chr, range(ord('a'), ord('z')+1)), heights))
word = input().strip()
print(len(word) * max(map(lambda x: h[x], word)))
