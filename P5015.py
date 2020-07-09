from sys import stdin
pattern = stdin.readline().rstrip()
file_cnt = int(stdin.readline().rstrip())
for _ in range(file_cnt):
    file = stdin.readline().rstrip()
    cache = [[False] * (len(file) + 1) for _ in range(len(pattern) + 1)]
    cache[len(pattern)][len(file)] = True
    for pi in range(len(pattern) - 1, -1, -1):
        for fi in range(len(file), -1, -1):
            if pattern[pi] == '*':
                cache[pi][fi] = cache[pi + 1][fi] or (fi < len(file) and cache[pi][fi + 1])
            elif fi < len(file) and pattern[pi] == file[fi]:
                cache[pi][fi] = cache[pi + 1][fi + 1]
    if cache[0][0]:
        print(file)