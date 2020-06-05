#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<int, int> cards;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ++cards[num];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int num;
        cin >> num;
        cout << cards[num] << ' ';
    }
}