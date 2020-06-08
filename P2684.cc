#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int P;
    cin >> P;
    while (P--) {
        int freq[8] = {};
        char attempt[41];
        cin >> attempt;
        for (int i = 2; i < 40; ++i) {
            ++freq[(attempt[i - 2] == 'H') << 2 | (attempt[i - 1] == 'H') << 1 | attempt[i] == 'H'];
        }
        for (int i = 0; i < 8; ++i) {
            cout << freq[i] << ' ';
        }
        cout << '\n';
    }
}