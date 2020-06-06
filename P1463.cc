#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int memo[1'000'001];
    memo[1] = 0;
    for (int i = 2; i <= n; ++i) {
        auto x = memo[i - 1];
        if (!(i & 1)) {
            x = min(x, memo[i >> 1]);
        }
        if (!(i % 3)) {
            x = min(x, memo[i / 3]);
        }
        memo[i] = x + 1;
    }
    cout << memo[n];
}