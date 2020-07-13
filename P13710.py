from sys import stdin
n = int(stdin.readline().rstrip())
seq = list(map(int, stdin.readline().split()))
total = 0
for bit in range(32):
    one_count = 0
    total_count = 0
    mask = 1 << bit
    for i, num in enumerate(seq):
        if num & mask:
            one_count = i - one_count + 1
        total_count += one_count
    total += total_count << bit
print(total)