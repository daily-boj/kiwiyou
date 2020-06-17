import sys
a = [x for x in range(1,31)]
for n in sys.stdin.readlines():
    a.remove(int(n.rstrip()))
print('\n'.join(map(str, a)))