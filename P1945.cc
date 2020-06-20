#include <bits/stdc++.h>
using namespace std;
struct Frac {
    long long u, d;
    bool operator<(const Frac& x) const {
        return u * x.d < d * x.u;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<Frac, bool>> segs;
    segs.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        int top, left, bottom, right;
        cin >> left >> bottom >> right >> top;
        segs.emplace_back(Frac { .u = bottom, .d = right }, false);
        segs.emplace_back(Frac { .u = top, .d = left }, true);
    }
    sort(segs.begin(), segs.end());
    int max_depth = 0;
    int depth = 0;
    for (auto& [_, is_close] : segs) {
        if (is_close) --depth;
        else ++depth;
        max_depth = max(max_depth, depth);
    }
    cout << max_depth;
}