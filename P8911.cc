#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int units;
    cin >> units;
    while (units--) {
        int x = 0, y = 0;
        int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;
        int dx = 0, dy = 1;
        string move;
        cin >> move;
        for (auto c : move) {
            switch (c) {
            case 'F':
                x += dx;
                y += dy;
                break;
            case 'B':
                x -= dx;
                y -= dy;
                break;
            case 'L':
                dx -= dy;
                dy += dx;
                dx -= dy;
                break;
            case 'R':
                dx += dy;
                dy -= dx;
                dx += dy;
                break;
            }
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }
        cout << ((max_x - min_x) * (max_y - min_y)) << '\n';
    }
}