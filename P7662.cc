#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        map<int, int> q;
        int k;
        cin >> k;
        while (k--) {
            char op;
            int x;
            cin >> op >> x;
            if (op == 'D' && !q.empty()) {
                if (x == 1) {
                    if (!--q.rbegin()->second) {
                        q.erase(q.rbegin()->first);
                    }
                } else {
                    if (!--q.begin()->second) {
                        q.erase(q.begin());
                    }
                }
            } else if (op == 'I') {
                ++q[x];
            }
        }
        if (q.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << q.rbegin()->first << ' ' << q.begin()->first << '\n';
        }
    }
}