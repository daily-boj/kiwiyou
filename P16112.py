import sys
n, k = map(int, sys.stdin.readline().split())
quests = list(map(int, sys.stdin.readline().split()))
quests.sort(reverse=True)
if n > 1:
    total = quests[0]
    for i in range(1, n - 1):
        quests[i] += quests[i - 1]
        if i >= k:
            total += quests[i] - quests[i - k]
        else:
            total += quests[i]
    print(total)
else:
    print(0)