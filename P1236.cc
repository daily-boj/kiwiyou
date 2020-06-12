#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    char castle[51];
    bool rows[50] = {}, cols[50] = {};
    for (int i = 0; i < h; ++i) {
        cin >> castle;
        for (int j = 0; j < w; ++j) {
            if (castle[j] == 'X') {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    int empty_row = count(rows, rows + h, false);
    int empty_col = count(cols, cols + w, false);
    cout << max(empty_row, empty_col);
}