import sys
for x in map(int, sys.stdin.readlines()):
    if x == 0:
        break
    if x < 0:
        for p in range(31, 0, -2):
            low, high = 2, -x
            while low < high:
                mid = (low + high) // 2
                if mid ** p < -x:
                    low = mid + 1
                else:
                    high = mid
            if low ** p == -x:
                print(p)
                break
    else:
        for p in range(32, 0, -1):
            low, high = 2, x
            while low < high:
                mid = (low + high) // 2
                if mid ** p < x:
                    low = mid + 1
                else:
                    high = mid
            if low ** p == x:
                print(p)
                break