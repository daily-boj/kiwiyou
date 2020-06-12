#include <bits/stdc++.h>
using namespace std;

int main() {
    char map[50][51];
    int w, h;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> map[i];
    }
    int max_dist = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (map[i][j] == 'W') continue;
            bool v[50][50] = {};
            v[i][j] = true;
            queue<pair<int, int>> next;
            int distance = 0;
            int child_cur = 1;
            int child_next = 0;
            next.emplace(i, j);
            while (!next.empty()) {
                auto [y, x] = next.front();
                next.pop();
                if (y > 0 && !v[y - 1][x] && map[y - 1][x] == 'L') {
                    next.emplace(y - 1, x);
                    v[y - 1][x] = true;
                    ++child_next;
                }
                if (x > 0 && !v[y][x - 1] && map[y][x - 1] == 'L') {
                    next.emplace(y, x - 1);
                    v[y][x - 1] = true;
                    ++child_next;
                }
                if (y < h - 1 && !v[y + 1][x] && map[y + 1][x] == 'L') {
                    next.emplace(y + 1, x);
                    v[y + 1][x] = true;
                    ++child_next;
                }
                if (x < w - 1 && !v[y][x + 1] && map[y][x + 1] == 'L') {
                    next.emplace(y, x + 1);
                    v[y][x + 1] = true;
                    ++child_next;
                }
                if (--child_cur == 0) {
                    ++distance;
                    child_cur = child_next;
                    child_next = 0;
                }
            }
            max_dist = max(max_dist, distance);
        }
    }
    cout << (max_dist - 1);
}