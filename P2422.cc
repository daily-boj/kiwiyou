#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int kind;
    int try_ban;
    bool banned[201][201] = { false, };
    cin >> kind >> try_ban;
    while (try_ban-- > 0) {
        int a, b;
        cin >> a >> b;
        banned[a][b] = banned[b][a] = true;
    }
    int count = 0;
    for (int i = 3; i <= kind; ++i) {
        for (int j = 2; j < i; ++j) {
            if (banned[j][i]) {
                continue;
            }
            for (int k = 1; k < j; ++k) {
                if (banned[k][i] || banned[k][j]) {
                    continue;
                }
                ++count;
            }
        }
    }
    cout << count;
}