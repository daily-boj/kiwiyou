from sys import stdin
pattern = stdin.readline().rstrip()
plen = len(pattern)
file_cnt = int(stdin.readline().rstrip())
for _ in range(file_cnt):
    file = stdin.readline().rstrip()
    flen = len(file)
    cache = [[False] * (flen + 1) for _ in range(plen + 1)]
    cache[plen][flen] = True
    for pi in range(plen - 1, -1, -1):
        for fi in range(flen, -1, -1):
            if pattern[pi] == '*':
                cache[pi][fi] = cache[pi + 1][fi] or (fi < flen and cache[pi][fi + 1])
            elif fi < flen and pattern[pi] == file[fi]:
                cache[pi][fi] = cache[pi + 1][fi + 1]
    if cache[0][0]:
        print(file)