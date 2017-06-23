import re

langs = ['C', 'CPP', 'JAVA', 'PYTHON', 'PERL', 'PHP', 'RUBY', 'CSHARP', 'HASKELL', 'CLOJURE', 'BASH', 'SCALA', 'ERLANG', 'CLISP', 'LUA', 'BRAINFUCK', 'JAVASCRIPT', 'GO', 'D', 'OCAML', 'R', 'PASCAL', 'SBCL', 'DART', 'GROOVY', 'OBJECTIVEC']
query_string = '(' + '|'.join(list(map(lambda x: r'\s' + x + r'$', langs))) + ')'
for i in range(int(input())):
	print('VALID' if len(re.findall(query_string, input())) != 0 else 'INVALID')
