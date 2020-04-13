meetings = [[int(t) for t in input().split(' ')] for _ in range(0, int(input()))]
meetings.sort(key=lambda m: m[0])
meetings.sort(key=lambda m: m[1])

last_end = 0
available = 0
for meeting in meetings:
    if meeting[0] < last_end:
        continue
    last_end = meeting[1]
    available += 1

print(available)