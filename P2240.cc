#include <bits/stdc++.h>
using namespace std;

int main() {
    int time, max_move;
    cin >> time >> max_move;
    int prev_plum[31][2] = {};
    int plum[31][2] = {};
    while (time--) {
        int tree;
        cin >> tree;
        --tree;
        plum[0][0] = prev_plum[0][0] + !tree;
        for (int move = 1; move <= max_move; ++move) {
            plum[move][tree] = max(prev_plum[move][tree], prev_plum[move - 1][!tree]) + 1;
            plum[move][!tree] = max(prev_plum[move][!tree], prev_plum[move - 1][tree]);
        }
        memcpy(prev_plum, plum, sizeof(plum));
    }
    cout << *max_element(&prev_plum[0][0], &prev_plum[0][0] + 62);
}