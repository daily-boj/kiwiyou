#include <bits/stdc++.h>
using namespace std;
int conv(char c) {
    switch (c) {
    case 'A': return 0;
    case 'E': return 1;
    case 'I': return 2;
    case 'O': return 3;
    case 'U': return 4;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    string dict[16];
    queue<int> visit;
    int mask = 1;
    unsigned long dp[65536][5] = {};
    for (int i = 0; i < n; ++i) {
        cin >> dict[i];
        visit.push(mask);
        dp[mask][conv(*dict[i].rbegin())] = dict[i].length();
        mask <<= 1;
    }
    int max_checked = 0;
    while (!visit.empty()) {
        auto current = visit.front();
        max_checked = max(max_checked, current);
        visit.pop();
        for (int i = 0, mask = 1; i < n; ++i, mask <<= 1) {
            if (current & mask) continue;
            auto& word = dict[i];
            auto to_connect = dp[current][conv(word[0])];
            if (!to_connect) continue;
            auto& to_change = dp[current | mask][conv(*word.rbegin())];
            auto new_value = to_connect + word.length();
            if (new_value > to_change) {
                to_change = new_value;
                visit.push(current | mask);
            }
        }
    }
    unsigned long max_point = 0;
    for (int i = 1; i <= max_checked; ++i) {
        for (int j = 0; j < 5; ++j) {
            max_point = max(max_point, dp[i][j]);
        }
    }
    cout << max_point;
}