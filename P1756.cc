#include <bits/stdc++.h>
using namespace std;

int main() {
    int depth;
    int doughs;
    cin >> depth >> doughs;
    int oven[300'000];
    int possible = 2147483647;
    for (int i = 0; i < depth; ++i) {
        cin >> oven[i];
        possible = min(possible, oven[i]);
        oven[i] = possible;
    }
    int current_depth = depth;
    for (int i = 0; i < doughs; ++i) {
        int radius;
        cin >> radius;
        if (current_depth < 0) {
            cout << "0\n";
            return 0;
        }
        while (current_depth-- > 0) {
            if (oven[current_depth] >= radius) {
                break;
            }
        }
    }
    cout << (current_depth + 1);
}