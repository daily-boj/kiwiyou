#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    int t[1000000];
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int low = 0, high = 1000000000;
    while (low < high) {
        int mid = (low + high) >> 1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += max(0, t[i] - mid);
        }
        if (sum >= m) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << (low - 1);
}