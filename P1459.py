x, y, w, s = map(int, input().split())
if x > y:
    x, y = y, x
y -= x
print(min(x * 2 * w, x * s) + min(y // 2 * 2 * s + y % 2 * w, y * w))