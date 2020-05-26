#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    auto radius = n >> 1;
    auto rsq = radius * radius;
    int count = 0;
    decltype(n) x = 0;
    decltype(x) xsq = 0;
    decltype(x) xpsq = 1;
    while (x < radius) {
        decltype(x) upper = ceil(sqrt((long double)(rsq - xsq)));
        decltype(x) lower = floor(sqrt((long double)(rsq - xpsq)));
        count += upper - lower;
        ++x;
        xsq += (x << 1);
        xpsq += (x << 1);
        --xsq;
        ++xpsq;
    }
    cout << (count << 2);
}
