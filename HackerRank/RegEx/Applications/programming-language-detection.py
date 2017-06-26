import sys, re

def is_c(s):
    return re.findall(r'#include', s) != []

def is_java(s):
    return re.findall(r'import java', s) != []

def is_python(s):
    return re.findall(r'(#|def)\s', s) != []

s = ''
for i in sys.stdin:
    s = s + ' ' + i
print(['C', 'Java', 'Python'][[is_c(s), is_java(s), is_python(s)].index(True)])
