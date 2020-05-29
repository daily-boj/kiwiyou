#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> vertices[100'000];
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i].first >> vertices[i].second;
    }
    sort(vertices, vertices + n);
    int vertical = 0;
    for (int i = 0; i < n; i += 2) {
        vertical += vertices[i + 1].second - vertices[i].second;
    }
    sort(vertices, vertices + n, [](auto& p1, auto& p2){ return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second; });
    int horizontal = 0;
    for (int i = 0; i < n; i += 2) {
        horizontal += vertices[i + 1].first - vertices[i].first;
    }
    cout << (vertical + horizontal);
}