#include <bits/stdc++.h>
using namespace std;

int main() {
    int stairs[1 << 10][10] = {};
    int alt[1 << 10][10] = {};
    for (int i = 0; i <= 9; ++i) {
        stairs[1 << i][i] = 1;
    }
    int n;
    cin >> n;
    while (--n) {
        for (int i = 0; i < 1 << 10; ++i) {
            alt[i | 1][0] += stairs[i][1];
            alt[i | 1][0] %= 1000000000;
            for (int digit = 1; digit <= 8; ++digit) {
                alt[i | (1 << digit)][digit] += (stairs[i][digit - 1] + stairs[i][digit + 1]) % 1000000000;
                alt[i | (1 << digit)][digit] %= 1000000000;
            }
            alt[i | (1 << 9)][9] += stairs[i][8];
            alt[i | (1 << 9)][9] %= 1000000000;
        }
        memcpy(stairs, alt, 10 * (1 << 10) * sizeof(int));
        memset(alt, 0, 10 * (1 << 10) * sizeof(int));
    }
    int count = 0;
    for (int i = 1; i <= 9; ++i) {
        count += stairs[(1 << 10) - 1][i];
        count %= 1000000000;
    }
    cout << count;
}