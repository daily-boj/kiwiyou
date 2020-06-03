#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int count;
    cin >> count;
    long long partials[100001];
    partials[0] = 0;
    for (int i = 1; i <= count; ++i) {
        cin >> partials[i];
        partials[i] += partials[i - 1];
    }
    long long to_find;
    cin >> to_find;
    long long intervals = 0;
    for (int i = 1; i <= count; ++i) {
        intervals += lower_bound(partials, partials + i, partials[i] - to_find) - partials;
    }
    cout << intervals;
}