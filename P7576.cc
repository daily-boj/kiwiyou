#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> m >> n;
    int totmatoes[1000][1000];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> totmatoes[i][j];
        }
    }

    int max_depth = 0;
    bool visited[1000][1000] = {};
    queue<pair<int, int>> next;
    int depth = 0;
    int children_left = 0;
    int children_next = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (totmatoes[i][j] == 1) {
                next.emplace(i, j);
                ++children_left;
                visited[i][j] = true;
            }
        }
    }
    while (!next.empty()) {
        auto [y, x] = next.front();
        next.pop();
        if (x > 0 && !visited[y][x - 1] && !totmatoes[y][x - 1]) {
            visited[y][x - 1] = true;
            next.emplace(y, x - 1);
            ++children_next;
        }
        if (x < m - 1 && !visited[y][x + 1] && !totmatoes[y][x + 1]) {
            visited[y][x + 1] = true;
            next.emplace(y, x + 1);
            ++children_next;
        }
        if (y > 0 && !visited[y - 1][x] && !totmatoes[y - 1][x]) {
            visited[y - 1][x] = true;
            next.emplace(y - 1, x);
            ++children_next;
        }
        if (y < n - 1 && !visited[y + 1][x] && !totmatoes[y + 1][x]) {
            visited[y + 1][x] = true;
            next.emplace(y + 1, x);
            ++children_next;
        }
        if (!--children_left) {
            ++depth;
            children_left = children_next;
            children_next = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && totmatoes[i][j] == 0) {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << --depth;
}