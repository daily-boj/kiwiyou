#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    bool sieve[1001] = {};
    sieve[1] = true;
    for (int i = 2; i <= 1000; ++i) {
        if (sieve[i]) continue;
        for (long long mark = (long long) i * i; mark <= 1000; mark += i) {
            sieve[mark] = true;
        }
    }
    int n;
    cin >> n;
    int count = 0;
    while (n--) {
        int number;
        cin >> number;
        count += !sieve[number];
    }
    cout << count;
}