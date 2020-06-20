from decimal import *
getcontext().prec = 128
a, b, c = map(Decimal, map(int, input().split()))
x = (a + b + c) / Decimal(2)
S = (x * (x - a) * (x - b) * (x - c)).sqrt()
R = (a * b * c) / S / Decimal(4)
r = S / x
d = (R * (R - Decimal(2) * r)).sqrt()
k = R + r
[print(t) for t in [S, R, r, d, k]]