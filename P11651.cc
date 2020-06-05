#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int, int> p[100000];
    for (int i = 0; i < n; ++i) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        cout << p[i].second << ' ' << p[i].first << '\n';
    }
}