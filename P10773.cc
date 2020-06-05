#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k;
    cin >> k;
    deque<int> n;
    while (k--) {
        int x;
        cin >> x;
        x ? n.push_back(x) : n.pop_back();
    }
    cout << accumulate(n.begin(), n.end(), 0);
}