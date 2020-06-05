#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        stack<char> par;
        bool b = true;
        for (auto c : s) {
            switch (c) {
            case '(':
                par.push('(');
                break;
            case '[':
                par.push('[');
                break;
            case ']':
                if (par.empty() || par.top() != '[') {
                    b = false;
                } else {
                    par.pop();
                }
                break;
            case ')':
                if (par.empty() || par.top() != '(') {
                    b = false;
                } else {
                    par.pop();
                }
                break;
            }
            if (!b) break;
        }
        if (par.empty() && b) cout << "yes\n";
        else cout << "no\n";
    }
}