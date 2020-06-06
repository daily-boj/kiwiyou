#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int adj[100][100];
    fill((int*) adj, (int*) adj + 100 * 100, 1000);
    for (int i = 0; i < n; ++i) {
        adj[i][i] = 0;
    }
    vector<pair<int, int>> rel(m);
    for (int i = 0; i < m; ++i) {
        auto& [a, b] = rel[i];
        cin >> a >> b;
        --a, --b;
        adj[a][b] = adj[b][a] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    int min_num = 2147483647;
    int min_psn = 0;
    for (int i = 0; i < n; ++i) {
        auto num = accumulate(adj[i], adj[i + 1], 0);
        if (num < min_num) {
            min_num = num;
            min_psn = i + 1;
        }
    }
    cout << min_psn;
}