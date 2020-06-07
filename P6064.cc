#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int g = gcd(M, N);
        int l = M * N / g;
        --x, --y;
        int found = -1;
        while (x < l) {
            if (x % N == y) found = x + 1;
            x += M;
        }
        cout << found << '\n';
    }
}