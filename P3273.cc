#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int seq[100000];
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    sort(seq, seq + n);
    int x;
    cin >> x;
    long long count = 0;
    int index = 0;
    while (index < n) {
        int value = seq[index];
        auto [begin, end] = equal_range(seq + index + 1, seq + n, x - value);
        count += end - begin;
        ++index;
    }
    cout << count;
}