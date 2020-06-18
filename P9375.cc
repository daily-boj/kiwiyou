#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<string, int> clothes;
        while (n--) {
            string name, kind;
            cin >> name >> kind;
            ++clothes[kind];
        }
        int count = 1;
        for (auto& [_k, v] : clothes) {
            count *= v + 1;
        }
        cout << (count - 1) << '\n';
    }
}