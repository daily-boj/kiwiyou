#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int nums[n];
    copy_n(istream_iterator<int>(cin), n, nums);
    sort(nums, nums + n);
    bool ok[n];
    fill_n(ok, n, false);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            auto [begin, end] = equal_range(nums, nums + n, nums[i] + nums[j]);
            if (end - begin && ok[begin - nums]) continue;
            for (int k = begin - nums; k < end - nums; ++k) {
                if (k != i && k != j) {
                    ok[k] = true;
                }
            }
        }
    }
    cout << count(ok, ok + n, true);
}