def prog_date(year):
    if year <= 1918:
        feb_offset = year % 4 == 0
    else:
        feb_offset = year % 400 == 0 or year % 4 == 0 and year % 100 != 0
    days = [31, 28 + feb_offset - (year == 1918) * 13, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][::-1]
    d, m = 0, 0
    while d + days[-1] < 256:
        m, d = m + 1, d + days.pop()
    return (256 - d, m + 1, year)

print('{:0>2}.{:0>2}.{}'.format(*prog_date(int(input().strip()))))
