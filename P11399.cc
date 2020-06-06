#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int p[1000];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    for (int i = 1; i < n; ++i) {
        p[i] += p[i - 1];
    }
    cout << accumulate(p, p + n, 0);
}