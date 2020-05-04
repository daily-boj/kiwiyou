d1, d2, p1, p2 = map(int, input().split(' '))
if p1 >= p2:
    while True:
        if (p1 - p2) % d2 == 0:
            print(p1)
            break
        if p1 > 100000:
            print(-1)
            break
        p1 += d1
else:
    while True:
        if (p2 - p1) % d1 == 0:
            print(p2)
            break
        if p2 > 100000:
            print(-1)
            break
        p2 += d2
