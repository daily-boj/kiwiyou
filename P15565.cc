#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int dolls[n];
    copy_n(istream_iterator<int>(cin), n, dolls);
    vector<int> one_place;
    one_place.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (dolls[i] == 1) one_place.push_back(i);
    }
    if (one_place.size() < k) {
        cout << -1;
    } else {
        int min_size = n;
        for (int i = k - 1; i < one_place.size(); ++i) {
            min_size = min(min_size, one_place[i] - one_place[i - k + 1] + 1);
        }
        cout << min_size;
    }
}