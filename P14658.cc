#include <bits/stdc++.h>
using namespace std;

int main() {
    int field_w, field_h;
    int length;
    int count;
    cin >> field_w >> field_h >> length >> count;
    vector<pair<int, int>> stars;
    stars.reserve(length);
    while (count--) {
        int x, y;
        cin >> x >> y;
        stars.emplace_back(x, y);
    }
    sort(stars.begin(), stars.end());
    auto from_x = stars.begin();
    ptrdiff_t max_count = 0;
    while (from_x != stars.end()) {
        auto current_x = from_x->first;
        vector<int> in_x_bound;
        for (auto it = from_x; it != stars.end(); ++it) {
            if (it->first <= current_x + length) {
                in_x_bound.push_back(it->second);
            } else {
                break;
            }
        }
        if (in_x_bound.size() > max_count) {
            sort(in_x_bound.begin(), in_x_bound.end());
            auto from_y = in_x_bound.begin();
            while (from_y != in_x_bound.end()) {
                auto y_cap = upper_bound(from_y, in_x_bound.end(), *from_y + length);
                max_count = max(max_count, y_cap - from_y);
                from_y = upper_bound(from_y, in_x_bound.end(), *from_y);
            }
        }
        while (++from_x != stars.end()) {
            if (from_x->first != current_x) break;
        }
    }
    cout << (stars.size() - max_count);
}