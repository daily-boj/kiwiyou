#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long multiplier;
    cin >> multiplier;
    long long sum = 0;
    while (--n) {
        long long num;
        cin >> num;
        sum += multiplier * num;
        multiplier += num;
    }
    cout << sum;
}