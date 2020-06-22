#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    queue<long long> q;
    q.push(a);
    int depth = 1;
    int stage = 1, next_stage = 0;
    while (!q.empty()) {
        auto current = q.front();
        if (current == b) break;
        q.pop();
        if (current < b) {
            q.push(current << 1);
            q.push(current * 10 + 1);
            next_stage += 2;
        }
        if (!--stage) {
            ++depth;
            stage = next_stage;
            next_stage = 0;
        }
    }
    if (q.empty()) {
        cout << "-1";
    } else {
        cout << depth;
    }
}