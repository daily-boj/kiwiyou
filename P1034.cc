#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    char table[50][51];
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }
    int k;
    cin >> k;
    int max_yield = 0;
    for (int i = 0; i < n; ++i) {
        char table_if[50][51];
        int changed = 0;
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '0') {
                for (int t = 0; t < n; ++t) {
                    table_if[t][j] = table[t][j] == '0' ? '1' : '0';
                }
                ++changed;
            } else {
                for (int t = 0; t < n; ++t) {
                    table_if[t][j] = table[t][j];
                }
            }
        }
        if (changed <= k && (changed & 1) == (k & 1)) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                count += all_of(table_if[j], table_if[j] + m, [=](auto c){ return c == '1'; });
            }
            max_yield = max(max_yield, count);
        }
    }
    cout << max_yield;
}