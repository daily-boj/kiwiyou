#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> heap;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x) {
            heap.push(x);
        } else {
            cout << (heap.empty() ? 0 : (x = heap.top(), heap.pop(), x)) << '\n';
        }
    }
}