#include <bits/stdc++.h>
using namespace std;

bool check(bool broken[], int num) {
    do {
        if (broken[num % 10]) return false;
    } while (num /= 10);
    return true;
}

int digits(int num) {
    int count = 0;
    do ++count;
    while (num /= 10);
    return count;
}

int main() {
    int channel;
    cin >> channel;
    int m;
    cin >> m;
    if (m == 10) {
        cout << abs(channel - 100);
    } else {
        bool broken[10] = {};
        while (m--) {
            int b;
            cin >> b;
            broken[b] = true;
        }
        int min_press = numeric_limits<int>::max();
        for (int i = 0; i < 1000000; ++i) {
            if (check(broken, i)) {
                min_press = min(min_press, abs(channel - i) + digits(i));
            }
        }
        cout << min(min_press, abs(channel - 100));
    }
}