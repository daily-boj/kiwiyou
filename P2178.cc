#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    char board[100][101];
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    int max_depth = 0;
    bool visited[100][100] = {};
    queue<pair<int, int>> next;
    next.emplace(0, 0);
    visited[0][0] = true;
    int depth = 0;
    int children_left = 1;
    int children_next = 0;
    while (!next.empty()) {
        auto [y, x] = next.front();
        if (x == m - 1 && y == n - 1) {
            break;
        }
        next.pop();
        --children_left;
        for (int dx = -1; dx <= 1; dx += 2) {
            auto cx = x + dx;
            if (0 <= cx && cx < m && !visited[y][cx] && board[y][cx] == '1') {
                visited[y][cx] = true;
                next.emplace(y, cx);
                ++children_next;
            }
        }
        for (int dy = -1; dy <= 1; dy += 2) {
            auto cy = y + dy;
            if (0 <= cy && cy < n && !visited[cy][x] && board[cy][x] == '1') {
                visited[cy][x] = true;
                next.emplace(cy, x);
                ++children_next;
            }
        }
        if (!children_left) {
            ++depth;
            children_left = children_next;
            children_next = 0;
        }
    }
    cout << ++depth;
}