#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int, string> accounts[100000];
    for (int i = 0; i < n; ++i) {
        cin >> accounts[i].first >> accounts[i].second;
    }
    stable_sort(accounts, accounts + n, [](auto& p1, auto& p2){ return p1.first < p2.first; });
    for (int i = 0; i < n; ++i) {
        cout << accounts[i].first << ' ' << accounts[i].second << '\n';
    }
}