from decimal import *
context = getcontext()
context.prec = 128
context.rounding = ROUND_HALF_UP

def pi():
    getcontext().prec += 2
    three = Decimal(3)
    lasts, t, s, n, na, d, da = 0, three, 3, 1, 0, 0, 24
    while s != lasts:
        lasts = s
        n, na = n+na, na+8
        d, da = d+da, da+32
        t = (t * n) / d
        s += t
    getcontext().prec -= 2
    return +s

TAU = 2 * pi()
def sin(x):
    x = x % TAU
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s

a, b, c = map(Decimal, map(int, input().split()))
left = (c - b) / a
right = (c + b) / a
threshold = Decimal(1e-32)
while right - left >= threshold:
    mid = (left + right) / 2
    if a * mid + b * sin(mid) < c:
        left = mid
    else:
        right = mid
print(round(mid, 6))