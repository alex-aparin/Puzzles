gems = set(map(chr, range(ord('a'), ord('z')+1)))
for i in range(int(input().strip())):
   gems = gems & set(input().strip())
print(len(gems))
