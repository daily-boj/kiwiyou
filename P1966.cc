#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, pos;
        cin >> n >> pos;
        deque<pair<int, bool>> q;
        for (int i = 0; i < n; ++i) {
            int priority;
            cin >> priority;
            q.emplace_back(priority, i == pos);
        }
        int count = 1;
        while (!q.empty()) {
            auto next = q.front();
            q.pop_front();
            if (find_if(q.begin(), q.end(), [=](auto p){ return p.first > next.first; }) != q.end()) {
                q.push_back(next);
            } else {
                if (next.second) {
                    cout << count << '\n';
                    break;
                }
                ++count;
            }
        }
    }
}