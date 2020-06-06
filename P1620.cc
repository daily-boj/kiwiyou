#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string by_index[100000];
    map<string, int> by_name;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> by_index[i];
        by_name[by_index[i]] = i + 1;
    }
    while (m--) {
        string s;
        cin >> s;
        if (s[0] & 0x40) {
            cout << by_name[s] << '\n';
        } else {
            cout << by_index[stoi(s) - 1] << '\n';
        }
    }
}