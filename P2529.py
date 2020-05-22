from sys import stdin

count = int(stdin.readline())
inequalities = stdin.readline().rstrip().split()

maxmimum = []
stack = []
for i, inequality in enumerate(inequalities):
    stack.append(9 - i)
    if inequality == '>':
        while stack:
            maxmimum.append(stack.pop())
maxmimum.append(9 - count)
while stack:
    maxmimum.append(stack.pop())
print(''.join(map(str, maxmimum)))

minimum = []
# stack = []
for i, inequality in enumerate(inequalities):
    stack.append(i)
    if inequality == '<':
        while stack:
            minimum.append(stack.pop())
minimum.append(count)
while stack:
    minimum.append(stack.pop())
print(''.join(map(str, minimum)))
