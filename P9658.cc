#include <bits/stdc++.h>
using namespace std;

int main() {
    int stones;
    cin >> stones;
    int winner[1000] = { 3, 0, 3, 0, };
    auto result = "SK\0CY";
    for (int i = 4; i < stones; ++i) {
        winner[i] = !(winner[i - 1] || winner[i - 3] || winner[i - 4]) * 3;
    }
    cout << (result + winner[stones - 1]);
}