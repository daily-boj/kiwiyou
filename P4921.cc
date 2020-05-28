#include <bits/stdc++.h>
using namespace std;

bool is_correct(const string& s) {
    if (s[0] != '1' || s.back() != '2') {
        return false;
    } else {
        for (int i = 1; i < s.length(); ++i) {
            auto prev = s[i - 1];
            switch (s[i]) {
            case '2':
            case '3':
                if (prev == '4' || prev == '6') {
                    break;
                } else {
                    return false;
                }
            case '4':
            case '5':
                if (prev == '1' || prev == '3') {
                    break;
                } else {
                    return false;
                }
            case '6':
            case '7':
                if (prev == '8') {
                    break;
                } else {
                    return false;
                }
            case '8':
                if (prev == '5' || prev == '7') {
                    break;
                } else {
                    return false;
                }
            default:
                return false;
            }
        }
        return true;
    }
}

int main() {
    for (int i = 1; ; ++i) {
        string s;
        cin >> s;
        if (s[0] == '0') {
            break;
        }
        cout << i << (is_correct(s) ? ". VALID\n" : ". NOT\n");
    }
}