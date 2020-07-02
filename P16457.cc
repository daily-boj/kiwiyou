#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    int skills[m];
    for (int i = 0; i < m; ++i) {
        int mask = 0;
        for (int j = 0; j < k; ++j) {
            int skill;
            cin >> skill;
            mask |= 1 << (skill - 1);
        }
        skills[i] = mask;
    }
    int set = (1 << n) - 1;
    int max_q = 0;
    int limit = set << n;
    while (true) {
        int count = 0;
        for (int i = 0; i < m; ++i) {
            if ((set & skills[i]) == skills[i]) {
                ++count;
            }
        }
        max_q = max(max_q, count);
        if (set == limit) break;
        int t = set | (set - 1);
        set = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(set) + 1));
    }
    cout << max_q;
}