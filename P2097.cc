#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2, sq = 4;
    while (i <= 22361) {
        if (n <= sq) {
            cout << ((i - 1) << 2);
            break;
        } else if (n <= sq + i) {
            cout << ((i - 1) << 2 | 2);
            break;
        }
        ++i;
        sq += (i << 1) - 1;
    }
}