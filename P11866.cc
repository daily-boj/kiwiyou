#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    deque<int> p;
    for (int i = 1; i <= n; ++i) {
        p.push_back(i);
    }
    deque<int> seq;
    int counter = 0;
    while (!p.empty()) {
        counter = (counter + 1) % k;
        if (!counter) {
            seq.push_back(p.front());
        } else {
            p.push_back(p.front());
        }
        p.pop_front();
    }
    auto it = seq.begin();
    cout << '<' << *it++;
    for (; it != seq.end(); ++it) {
        cout << ", " << *it;
    }
    cout << '>';
}