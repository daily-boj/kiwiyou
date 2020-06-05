#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int list[500000];
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }
    int am = accumulate(list, list + n, 0);
    sort(list, list + n);
    int med = list[n >> 1];
    int r = list[n - 1] - list[0];
    vector<int> max_f;
    int fst_f = 0;
    int freq = 0, cur = -1;
    for (int i = 0; i < n; ++i) {
        if (cur != list[i]) {
            if (freq > fst_f) {
                max_f.clear();
                fst_f = freq;
                max_f.push_back(cur);
            } else if (freq == fst_f) {
                max_f.push_back(cur);
            }
            cur = list[i];
            freq = 1;
        } else {
            ++freq;
        }
    }
    if (freq > fst_f) {
        max_f.clear();
        fst_f = freq;
        max_f.push_back(cur);
    } else if (freq == fst_f) {
        max_f.push_back(cur);
    }
    cout << round(am / (long double) n) << '\n';
    cout << med << '\n';
    cout << (max_f.size() > 1 ? max_f[1] : max_f[0]) << '\n';
    cout << r;
}