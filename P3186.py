from sys import stdin
k, l, n = map(int, stdin.readline().split())
s = stdin.readline()
state = 'Idle'
time = 0
flushed = False
for i, p in enumerate(s):
    if state == 'Idle':
        if p == '1':
            time += 1
            if time >= k:
                state = 'Use'
                time = 0
        else:
            time = 0
    else:
        if p == '0':
            time += 1
            if time >= l:
                state = 'Idle'
                flushed = True
                print(i + 1)
                time = 0
        else:
            time = 0
if state == 'Use':
    flushed = True
    print(n + l - time)
if not flushed:
    print('NIKAD')