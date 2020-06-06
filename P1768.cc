#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set<string> hear;
    set<string> see;
    copy_n(istream_iterator<string>(cin), n, inserter(hear, hear.begin()));
    copy_n(istream_iterator<string>(cin), m, inserter(see, see.begin()));
    vector<string> hear_see;
    hear_see.reserve(min(hear.size(), see.size()));
    set_intersection(hear.begin(), hear.end(), see.begin(), see.end(), back_inserter(hear_see));
    cout << hear_see.size() << '\n';
    for (auto& name : hear_see) {
        cout << name << '\n';
    }
}