count = int(input())
inequalities = input().split()

maxmimum = []
stack = []
for i, inequality in enumerate(inequalities):
    if inequality == '<':
        stack.append(9 - i)
    else:
        maxmimum.append(9 - i)
        while stack:
            maxmimum.append(stack.pop())
maxmimum.append(9 - count)
while stack:
    maxmimum.append(stack.pop())
print(''.join(str(n) for n in maxmimum))

minimum = []
# stack = []
for i, inequality in enumerate(inequalities):
    if inequality == '<':
        stack.append(i)
        while stack:
            minimum.append(stack.pop())
    else:
        stack.append(i)
minimum.append(count)
while stack:
    minimum.append(stack.pop())
print(''.join(str(n) for n in minimum))
