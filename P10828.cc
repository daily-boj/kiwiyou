#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    stack<int> s;
    while (q--) {
        string op;
        cin >> op;
        if (op[1] == 'u') {
            int x;
            cin >> x;
            s.push(x);
        } else if (op[0] == 'p') {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (op[1] == 'i') {
            cout << s.size() << '\n';
        } else if (op[1] == 'm') {
            cout << s.empty() << '\n';
        } else if (op[1] == 'o') {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << '\n';
            }
        }
    }
}