#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int points;
    cin >> points;
    bool adj[100][100];
    for (int i = 0; i < points; ++i) {
        for (int j = 0; j < points; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int m = 0; m < points; ++m) {
        for (int s = 0; s < points; ++s) {
            for (int d = 0; d < points; ++d) {
                if (adj[s][m] && adj[m][d]) {
                    adj[s][d] = true;
                }
            }
        }
    }
    for (int i = 0; i < points; ++i) {
        for (int j = 0; j < points; ++j) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}