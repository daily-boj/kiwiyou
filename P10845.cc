#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin >> n;
    queue<int> q;
    while (n--) {
        string op;
        cin >> op;
        if (op[0] == 's') {
            cout << q.size() << '\n';
        } else if (op[0] == 'e') {
            cout << q.empty() << '\n';
        } else if (op[0] == 'f') {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } else if (op[0] == 'b') {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        } else if (op[1] == 'o') {
            cout << (q.empty() ? -1 : (t = q.front(), q.pop(), t)) << '\n';
        } else {
            cin >> t;
            q.push(t);
        }
    }
}