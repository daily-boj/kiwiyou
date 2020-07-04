s = input()
t = input()

def solve(t):
    global s
    if len(t) == len(s):
        return t == s
    if t[-1] == 'A' and solve(t[:-1]):
        return True
    return t[0] == 'B' and solve(t[:0:-1])

print(1 if solve(t) else 0)
