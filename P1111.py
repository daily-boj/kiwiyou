n = int(input())
l = list(map(int, input().split()))
if n == 1:
    print('A')
    exit(0)
d = l[1] - l[0]
if d == 0:
    print(l[0] if all(x == l[0] for x in l) else 'B')
elif n == 2:
    print('A')
else:
    a = (l[2] - l[1]) // d
    b = l[1] - a * l[0]
    print((a * l[-1] + b) if all(l[x + 1] == a * l[x] + b for x in range(n - 1)) else 'B')