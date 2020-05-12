n, m = map(int, input().split(' '))
satisfaction = [[int(s) for s in input().split(' ')] for x in range(0, n)]

max_score = 0
for chicken1 in range(0, m - 2):
    for chicken2 in range(chicken1 + 1, m - 1):
        for chicken3 in range(chicken2 + 1, m):
            score = sum(max(personal[chicken1], personal[chicken2], personal[chicken3]) for personal in satisfaction)
            max_score = max(score, max_score)
print(max_score)