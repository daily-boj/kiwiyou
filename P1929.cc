#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int low, high;
    cin >> low >> high;
    bool sieve[1000001] = {};
    sieve[1] = true;
    for (int i = 2; i <= high; ++i) {
        if (sieve[i]) continue;
        for (long long mark = (long long) i * i; mark <= high; mark += i) {
            sieve[mark] = true;
        }
    }
    for (int i = low; i <= high; ++i) {
        if (!sieve[i]) {
            cout << i << '\n';
        }
    }
}