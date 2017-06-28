def count_substring(string, sub_string):
    s_count = 0
    for i in range(0, len(string) - len(sub_string) + 1):
        s_count += 1 if string[i:i+len(sub_string)] == sub_string else 0
    return s_count
