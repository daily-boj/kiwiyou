#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    cout << (next_permutation(s.begin(), s.end()) ? s.c_str() : "0");
}