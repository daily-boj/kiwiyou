from sys import stdin
n, m = map(int, stdin.readline().split())
lattice = stdin.readlines()
count = 1
for y in range(n):
    for x in range(m):
        same = True
        if x > 0:
            same = same and lattice[y][x] == lattice[y][x - 1]
        if y > 0:
            same = same and lattice[y][x] == lattice[y - 1][x]
        if x < m - 1:
            same = same and lattice[y][x] == lattice[y][x + 1]
        if y < n - 1:
            same = same and lattice[y][x] == lattice[y + 1][x]
        if same:
            count = (count * 2) % 1000000007
print(count)
