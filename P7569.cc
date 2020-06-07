#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, h;
    cin >> m >> n >> h;
    int tomatoes[100][100][100];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> tomatoes[i][j][k];
            }
        }
    }

    int max_depth = 0;
    int visited[100][100][100] = {};
    queue<tuple<int, int, int>> next;
    int depth = 0;
    int children_left = 0;
    int children_next = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (tomatoes[i][j][k] == 1) {
                    next.emplace(i, j, k);
                    ++children_left;
                    visited[i][j][k] = true;
                }
            }
        }
    }
    while (!next.empty()) {
        auto [z, y, x] = next.front();
        next.pop();
        for (int delta = -1; delta <= 1; delta += 2) {
            auto cx = x + delta;
            if (0 <= cx && cx < m && !visited[z][y][cx] && !tomatoes[z][y][cx]) {
                visited[z][y][cx] = depth + 2;
                next.emplace(z, y, cx);
                ++children_next;
            }
            auto cy = y + delta;
            if (0 <= cy && cy < n && !visited[z][cy][x] && !tomatoes[z][cy][x]) {
                visited[z][cy][x] = depth + 2;
                next.emplace(z, cy, x);
                ++children_next;
            }
            auto cz = z + delta;
            if (0 <= cz && cz < h && !visited[cz][y][x] && !tomatoes[cz][y][x]) {
                visited[cz][y][x] = depth + 2;
                next.emplace(cz, y, x);
                ++children_next;
            }
        }
        if (!--children_left) {
            ++depth;
            children_left = children_next;
            children_next = 0;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (!visited[i][j][k] && tomatoes[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << --depth;
}