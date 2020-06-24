#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    int count[n + 1];
    fill_n(count, n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (count[i] != -1) continue;
        count[i] = sqrt(m / i);
        for (int j = 2; i * j * j <= n; ++j) {
            count[i * j * j] = count[i];
        }
    }
    cout << accumulate(count + 1, count + n + 1, 0);
}