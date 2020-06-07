#include <bits/stdc++.h>
using namespace std;

int board[2187][2187];

tuple<int, int, int> count(int x, int y, int size) {
    if (size == 1) {
        switch (board[x][y]) {
            case -1:
                return { 1, 0, 0 };
            case 0:
                return { 0, 1, 0 };
            case 1:
                return { 0, 0, 1 };
        }
    }
    size /= 3;
    int minus = 0, zero = 0, one = 0;
    for (int dx = 0; dx < 3; ++dx) {
        for (int dy = 0; dy < 3; ++dy) {
            auto [m, z, o] = count(x + dx * size, y + dy * size, size);
            minus += m;
            zero += z;
            one += o;
        }
    }
    if (minus == 9 && zero == 0 && one == 0) {
        return { 1, 0, 0 };
    } else if (minus == 0 && zero == 9 && one == 0) {
        return { 0, 1, 0 };
    } else if (minus == 0 && zero == 0 && one == 9) {
        return { 0, 0, 1 };
    } else {
        return { minus, zero, one };
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    auto [m, z, o] = count(0, 0, n);
    cout << m << '\n' << z << '\n' << o;
}