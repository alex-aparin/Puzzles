caches = [0] * 26
for x in input().replace(' ', ''):
    caches[ord(x.lower()) - ord('a')] += 1
print('pangram' if caches.count(0) == 0 else 'not pangram')
