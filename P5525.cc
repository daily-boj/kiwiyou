#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int ioi = 0;
    int count = 0;
    for (int i = 2; i < m; ++i) {
        if (s[i - 2] == 'I' && s[i - 1] == 'O' && s[i] == 'I') {
            ++ioi;
        } else if (!(s[i - 2] == 'O' && s[i - 1] == 'I' && s[i] == 'O')) {
            if (ioi >= n) count += ioi - n + 1;
            ioi = 0;
        }
    }
    if (ioi >= n) count += ioi - n + 1;
    cout << count;
}