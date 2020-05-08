#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;
    int set = 0;
    char op[7];
    int arg;
    while (m--) {
        cin >> op;
        if (!strcmp(op, "add")) {
            cin >> arg;
            arg = 1 << arg;
            set |= arg;
        } else if (!strcmp(op, "remove")) {
            cin >> arg;
            arg = 1 << arg;
            set &= ~arg;
        } else if (!strcmp(op, "check")) {
            cin >> arg;
            arg = 1 << arg;
            cout << !!(set & arg) << '\n';
        } else if (!strcmp(op, "toggle")) {
            cin >> arg;
            arg = 1 << arg;
            set ^= arg;
        } else if (!strcmp(op, "all")) {
            set = 0x1FFFFF;
        } else {
            set = 0;
        }
    }
}