#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, bool>> time_open;
    time_open.reserve(n << 1);
    int point;
    for (int i = 0; i < n; ++i) {
        cin >> point;
        time_open.emplace_back(point, true);
        cin >> point;
        time_open.emplace_back(point, false);
    }
    sort(time_open.begin(), time_open.end());
    int depth = 0;
    int max_depth = 0;
    for (auto [_point, is_open] : time_open) {
        if (is_open) depth += 1;
        else depth -= 1;
        max_depth = max(max_depth, depth);
    }
    cout << max_depth;
}