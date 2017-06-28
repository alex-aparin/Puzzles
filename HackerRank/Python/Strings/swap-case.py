def swap_case(s):
    return ''.join(map(lambda x: x.lower() if x.isupper() else x.upper(),s))
