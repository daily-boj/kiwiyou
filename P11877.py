cnt, volume = map(int, input().split())
buffer = list(range(cnt - 1))
histogram = [cnt]
low = 0
while len(histogram) < cnt and volume > 0:
    to_make = min(volume, cnt - low - 2)
    histogram.append(cnt - to_make - 1)
    volume -= to_make
    buffer[cnt - to_make - 2] = -1
    low = cnt - to_make - 1
if volume > 0:
    print("-1")
elif cnt == 1:
    print("1")
else:
    while buffer:
        pop = buffer.pop()
        if pop >= 0:
            histogram.append(pop + 1)
    print(' '.join(map(str, histogram)))
