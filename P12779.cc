#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long a, b;
    cin >> a >> b;
    long long sqrt = 1;
    long long i = 1;
    int count = 0;
    while (sqrt <= b) {
        if (sqrt > a) {
            ++count;
        }
        sqrt += (i++ << 1) + 1;
    }
    long long x = b - a, y = count;
    while (y) {
        long long tmp = y;
        y = x % y;
        x = tmp;
    }
    if (count) {
        cout << (count / x) << '/' << ((b - a) / x);
    } else {
        cout << '0';
    }
}