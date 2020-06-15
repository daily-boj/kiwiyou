#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int conv;
        cin >> conv;
        bool adj[103][103] = {};
        pair<int, int> items[103];
        cin >> items[0].first >> items[0].second;
        for (int i = 1; i <= conv; ++i) {
            cin >> items[i].first >> items[i].second;
        }
        cin >> items[conv + 1].first >> items[conv + 1].second;
        for (int i = 1; i <= conv + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(items[i].first - items[j].first) + abs(items[i].second - items[j].second) <= 1000) {
                    adj[i][j] = adj[j][i] = true;
                }
            }
        }
        for (int k = 0; k <= conv + 1; ++k) {
            for (int i = 0; i <= conv + 1; ++i) {
                for (int j = 0; j <= conv + 1; ++j) {
                    if (adj[i][k] && adj[k][j]) {
                        adj[i][j] = true;
                    }
                }
            }
        }
        cout << (adj[0][conv + 1] ? "happy\n" : "sad\n");
    }
}