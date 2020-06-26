a, b, n = map(int, input().split())
print(pow(1 << 31, n - 1, mod=1000000007))