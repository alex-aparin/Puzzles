pattern_mask = 1 << 33;
for i in range(int(input())):
    print((~(pattern_mask | int(input()))) & 0xFFFFFFFF)
