#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    int a[N];
    copy_n(istream_iterator<int>(cin), N, a);
    vector<int> search;
    search.reserve(N);
    search.push_back(a[0]);
    for (int i = 1; i < N; ++i) {
        if (a[i] > *search.rbegin()) {
            search.push_back(a[i]);
        } else {
            *upper_bound(search.begin(), search.end(), a[i]) = a[i];
        }
    }
    cout << (N - search.size());
}