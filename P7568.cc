#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int, int> d[50];
    for (int i = 0; i < n; ++i) {
        cin >> d[i].first >> d[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = 0; j < n; ++j) {
            count += (d[j].first > d[i].first && d[j].second > d[i].second);
        }
        cout << count << ' ';
    }
}