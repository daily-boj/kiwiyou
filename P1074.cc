#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, r, c;
    cin >> N >> r >> c;
    int size = 1 << N;
    int offset = 0;
    while (size > 1) {
        size >>= 1;
        offset <<= 2;
        if (c >= size) {
            c -= size;
            offset |= 1;
        }
        if (r >= size) {
            r -= size;
            offset |= 2;
        }
    }
    cout << offset;
}