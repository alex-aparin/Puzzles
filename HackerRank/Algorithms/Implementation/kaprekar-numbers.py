def digs(x):
    ds = 10
    while x // 10 != 0:
        ds, x = ds * 10, x // 10
    return ds
        
def is_kaprekar(x):
    sq_n, ds = x ** 2, digs(x)
    return sq_n // ds + sq_n % ds == x

kaprekars = False
for i in range(int(input()), int(input()) + 1):
    if is_kaprekar(i):
        kaprekars = True
        print(i, end=' ')
if not kaprekars:
    print('INVALID RANGE')
    
