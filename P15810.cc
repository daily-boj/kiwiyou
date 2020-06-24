#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    unsigned long long n, m;
    cin >> n >> m;
    unsigned long long a[n];
    copy_n(istream_iterator<int>(cin), n, a);
    unsigned long long low = 1, high = 1000000;
    while (low < high) {
        unsigned long long mid = (low + high) >> 1;
        unsigned long long count = accumulate(a, a + n, 0ULL, [=](unsigned long long prev, unsigned long long per_min) { return prev + mid / per_min; });
        if (count < m) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << low;
}