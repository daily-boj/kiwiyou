from sys import stdin
n = int(stdin.readline().rstrip())
board = [list(map(int, line.split())) for line in stdin.readlines()]
count = [[0] * n for _ in range(n)]
count[0][0] = 1
for y in range(n):
    for x in range(n):
        if board[y][x] == 0:
            continue
        if x + board[y][x] < n:
            count[y][x + board[y][x]] += count[y][x]
        if y + board[y][x] < n:
            count[y + board[y][x]][x] += count[y][x]
print(count[-1][-1])