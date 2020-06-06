#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int count = 0;
    while (n) {
        count += n /= 5;
    }
    cout << count;
}