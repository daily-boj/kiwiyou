#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin >> n;
    deque<int> d;
    while (n--) {
        string op;
        cin >> op;
        if (op[0] == 's') {
            cout << d.size() << '\n';
        } else if (op[0] == 'e') {
            cout << d.empty() << '\n';
        } else if (op[0] == 'f') {
            cout << (d.empty() ? -1 : d.front()) << '\n';
        } else if (op[0] == 'b') {
            cout << (d.empty() ? -1 : d.back()) << '\n';
        } else if (op[4] == 'f') {
            cout << (d.empty() ? -1 : (t = d.front(), d.pop_front(), t)) << '\n';
        } else if (op[4] == 'b') {
            cout << (d.empty() ? -1 : (t = d.back(), d.pop_back(), t)) << '\n';
        } else if (op[5] == 'f') {
            int x;
            cin >> x;
            d.push_front(x);
        } else {
            int x;
            cin >> x;
            d.push_back(x);
        }
    }
}