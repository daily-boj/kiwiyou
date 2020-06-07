#include <bits/stdc++.h>
using namespace std;

char m[25][26];
bool v[25][25];

void dfs(int x, int y, int& count, int size) {
    if (x > 0 && m[y][x - 1] == '1' && !v[y][x - 1]) {
        v[y][x - 1] = true;
        dfs(x - 1, y, ++count, size);
    }
    if (x + 1 < size && m[y][x + 1] == '1' && !v[y][x + 1]) {
        v[y][x + 1] = true;
        dfs(x + 1, y, ++count, size);
    }
    if (y > 0 && m[y - 1][x] == '1' && !v[y - 1][x]) {
        v[y - 1][x] = true;
        dfs(x, y - 1, ++count, size);
    }
    if (y < size && m[y + 1][x] == '1' && !v[y + 1][x]) {
        v[y + 1][x] = true;
        dfs(x, y + 1, ++count, size);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    vector<int> complexes;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j] || m[i][j] != '1') continue;
            v[i][j] = true;
            int count = 1;
            dfs(j, i, count, n);
            complexes.push_back(count);
        }
    }
    sort(complexes.begin(), complexes.end());
    cout << complexes.size() << '\n';
    for (auto count : complexes) {
        cout << count << '\n';
    }
}