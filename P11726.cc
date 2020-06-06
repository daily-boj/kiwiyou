#include <bits/stdc++.h>
using namespace std;

int main() {
    int prev[2] = {1, 1};
    int n;
    cin >> n;
    while (--n) {
        int next = (prev[0] + prev[1]) % 10007;
        prev[1] = prev[0];
        prev[0] = next;
    }
    cout << prev[0];
}