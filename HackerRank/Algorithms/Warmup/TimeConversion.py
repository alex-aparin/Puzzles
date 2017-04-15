time = input().strip()
hour = int(time[:2]) % 12
if (time[-2:] == 'PM'):
    hour = (hour + 12) % 24
print('{:0>2}'.format(hour) + time[2:-2])
