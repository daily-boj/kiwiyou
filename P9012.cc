#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int level = 0;
        bool failed = false;
        for (auto par : s) {
            level += par == '(' ? 1 : -1;
            if (level < 0) {
                failed = true;
                break;
            }
        }
        cout << (level != 0 || failed ? "NO\n" : "YES\n");
    }
}