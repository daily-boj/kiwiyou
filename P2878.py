from sys import stdin
M, N = map(int, stdin.readline().split())
candy = [int(line.rstrip()) for line in stdin.readlines()]
candy.sort()
want = sum(candy)
want -= M
rage = 0
for i in range(N):
    fail = min(candy[i], want // (N - i))
    rage += fail * fail
    want -= fail
print(rage % (2 ** 64))