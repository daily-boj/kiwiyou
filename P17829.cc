#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    while (n > 1) {
        for (int y = 0; y < n; y += 2) {
            for (int x = 0; x < n; x += 2) {
                int fst = matrix[y][x], snd = -10001;
                if (matrix[y + 1][x] > fst) {
                    snd = fst;
                    fst = matrix[y + 1][x];
                } else {
                    snd = matrix[y + 1][x];
                }
                if (matrix[y][x + 1] > fst) {
                    snd = fst;
                    fst = matrix[y][x + 1];
                } else if (matrix[y][x + 1] > snd) {
                    snd = matrix[y][x + 1];
                }
                if (matrix[y + 1][x + 1] > fst) {
                    snd = fst;
                    fst = matrix[y + 1][x + 1];
                } else if (matrix[y + 1][x + 1] > snd) {
                    snd = matrix[y + 1][x + 1];
                }
                matrix[y >> 1][x >> 1] = snd;
            }
        }
        n >>= 1;
    }
    cout << matrix[0][0];
}