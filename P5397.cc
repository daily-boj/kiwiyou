#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string tap;
        cin >> tap;
        list<char> edit;
        auto it = edit.begin();
        for (auto op : tap) {
            switch (op) {
            case '<':
                if (it != edit.begin()) {
                    --it;
                }
                break;
            case '>':
                if (it != edit.end()) {
                    ++it;
                }
                break;
            case '-':
                if (it != edit.begin()) {
                    it = edit.erase(--it);
                }
                break;
            default:
                it = edit.insert(it, op);
                ++it;
                break;
            }
        }
        for (auto c : edit) {
            cout << c;
        }
        cout << '\n';
    }
}