#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int slot_cnt;
    int query_cnt;
    cin >> slot_cnt >> query_cnt;
    bool slots[10000] = {};
    while (query_cnt--) {
        int start;
        int gap;
        cin >> start >> gap;
        for (--start; start < slot_cnt; start += gap) {
            slots[start] = true;
        }
    }
    cout << count(slots, slots + slot_cnt, false);
}