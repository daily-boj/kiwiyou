#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    bool adj[101][101] = {};
    while (c--) {
        int f, t;
        cin >> f >> t;
        adj[f][t] = adj[t][f] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (adj[i][k] && adj[k][j]) {
                    adj[i][j] = true;
                }
            }
        }
    }
    cout << count(adj[1] + 2, adj[1] + n + 1, true);
}