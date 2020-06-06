#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int prev[3] = {1, 1, 0};
        int n;
        cin >> n;
        while (--n) {
            int next = prev[0] + prev[1] + prev[2];
            prev[2] = prev[1];
            prev[1] = prev[0];
            prev[0] = next;
        }
        cout << prev[0] << '\n';
    }
}