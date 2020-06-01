#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int seq[1000000];
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    int test[1000000];
    for (int i = 0; i < n; ++i) {
        cin >> test[i];
    }
    // 정방향
    int it = find(test, test + n, seq[0]) - test;
    bool fw = true;
    for (int i = 0; i < n; ++i) {
        if (seq[i] != test[it]) {
            fw = false;
            break;
        }
        ++it;
        it %= n;
    }
    // 역방향
    reverse(test, test + n);
    it = find(test, test + n, seq[0]) - test;
    bool rev = true;
    for (int i = 0; i < n; ++i) {
        if (seq[i] != test[it]) {
            rev = false;
            break;
        }
        ++it;
        it %= n;
    }
    if (fw || rev) {
        cout << "good puzzle";
    } else {
        cout << "bad puzzle";
    }
}