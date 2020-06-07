#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        pair<int, char> v[10000] = {};
        queue<int> next;
        int f, t;
        cin >> f >> t;
        next.push(f);
        v[f].first = f;
        v[f].second = ' ';
        while (true) {
            int cur = next.front();
            if (cur == t) break;
            next.pop();
            auto doubled = (cur << 1) % 10000;
            auto decrease = (cur + 9999) % 10000;
            auto left = cur / 1000 + cur % 1000 * 10;
            auto right = cur % 10 * 1000 + cur / 10;
            if (!v[doubled].second) {
                v[doubled].first = cur;
                v[doubled].second = 'D';
                next.push(doubled);
            }
            if (!v[decrease].second) {
                v[decrease].first = cur;
                v[decrease].second = 'S';
                next.push(decrease);
            }
            if (!v[left].second) {
                v[left].first = cur;
                v[left].second = 'L';
                next.push(left);
            }
            if (!v[right].second) {
                v[right].first = cur;
                v[right].second = 'R';
                next.push(right);
            }
        }
        string ops;
        while (v[t].second != ' ') {
            ops.push_back(v[t].second);
            t = v[t].first;
        }
        reverse(ops.begin(), ops.end());
        cout << ops << '\n';
    }
}