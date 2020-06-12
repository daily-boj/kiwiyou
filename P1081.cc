#include <bits/stdc++.h>
using namespace std;
long long table[11] = {};
long long count(int n) {
    if (n < 0) return 0;
    int i = 0;
    long long base = 1;
    long long sum = 0;
    while (base <= n) {
        long long digit = n / base;
        long long lower = n % base;
        digit %= 10;
        sum += digit * (lower + 1);
        sum += digit * (digit - 1) * base >> 1;
        sum += digit * table[i];
        ++i;
        base *= 10;
    }
    return sum;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long base = 1;
    for (int i = 1; i < 11; ++i) {
        table[i] = 45LL * base + table[i - 1] * 10LL;
        base *= 10;
    }
    int l, u;
    cin >> l >> u;
    cout << (count(u) - count(l - 1));
}