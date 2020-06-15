#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int seq[100001];
    set<pair<int, int>> q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> seq[i];
        q.emplace(seq[i], i);
    }
    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            q.erase({ seq[i], i });
            seq[i] = v;
            q.emplace(v, i);
        } else {
            cout << q.begin()->second << '\n';
        }
    }
}