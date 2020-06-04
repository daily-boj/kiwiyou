#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a %= c;
    long long result = 1;
    while (b) {
        if (b & 1) {
            result *= a;
            result %= c;
        }
        a *= a;
        a %= c;
        b >>= 1;
    }
    cout << result;
}