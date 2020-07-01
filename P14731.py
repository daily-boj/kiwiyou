from sys import stdin
n = int(stdin.readline().rstrip())
rem = 0
mod = 1000000007
for line in stdin.readlines():
    c, k = map(int, line.split())
    rem = rem + (k * c * pow(2, k - 1, mod=mod)) % mod
    rem = rem % mod
print(rem)