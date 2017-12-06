def time_in_words(h, m):
    is_sec = m > 30
    pref = 'past' if not is_sec else 'to'
    m = m if not is_sec else 60 - m
    time_words =  {1  : 'one',      2  : 'two',      3  : 'three', 
                   4  : 'four',     5  : 'five',     6  : 'six', 
                   7  : 'seven',    8  : 'eight',    9  : 'nine', 
                   10 : 'ten',      11 : 'eleven',   12 : 'twelve',
                   13 : 'thirteen', 14 : 'fourteen', 15 : 'fifthteen',
                   16 : 'sixteen',  17 : 'seventeen', 18 : 'eighteen',
                   19 : 'nineteen', 
                   20 : 'twenty', 30 : 'thirty', 40 : 'fourty',   50 : 'fifty'}
    if m == 0:
        return "{0} o' clock".format(time_words[h])
    if m == 1:
        return "one minute {1} {2}".format(pref, time_words[h + is_sec])
    if m == 15:
        return "quarter {0} {1}".format(pref, time_words[h + is_sec])
    if m == 30:
        return "half {0} {1}".format(pref, time_words[h + is_sec])
    if m in time_words:
        return "{0} minutes {1} {2}".format(time_words[m], pref,  time_words[h + is_sec])
    return "{0} {1} minutes {2} {3}".format(time_words[(m // 10) * 10], time_words[m % 10], pref, time_words[h + is_sec])

print(time_in_words(int(input()), int(input())))
