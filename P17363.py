import sys
table = {'.':'.', 'O':'O', '-':'|', '|':'-', '/':'\\', '\\':'/', '^':'<', '<':'v', 'v':'>', '>':'^'}
print('\n'.join([''.join(table[c] for c in t) for t in zip(*[tuple(line.rstrip()) for line in sys.stdin.readlines()[1:]])][::-1]))