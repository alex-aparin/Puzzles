for t in range(int(input().strip())):
    n = int(input().strip())
    M = [[int(c) for c in input().strip().split()] for i in range(n)]
    conts, balls = {}, [0] * n
    for row in M:
        s = sum(row)
        if not s in conts:
            conts[s] = 0
        conts[s] += 1
        for i in range(n):
            balls[i] += row[i]
    answer = True
    for b in balls:
        answer = answer and b in conts
        if not answer:
            break
        conts[b] -= 1
        if conts[b] == 0:
            del conts[b]
    print('Possible' if answer else 'Impossible')
    
