#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int, int> tasks[100000];
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].second >> tasks[i].first;
    }
    sort(tasks, tasks + n);
    int count = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
        if (tasks[i].second >= end) {
            ++count;
            end = tasks[i].first;
        }
    }
    cout << count;
}