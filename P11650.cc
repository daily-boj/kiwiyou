#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int count;
    cin >> count;
    pair<int, int> points[100000];
    for (int i = 0; i < count; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points, points + count);
    for (int i = 0; i < count; ++i) {
        cout << points[i].first << ' ' << points[i].second << '\n';
    }
}