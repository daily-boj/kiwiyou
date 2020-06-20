#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> pws;
    while (n--) {
        string site, pw;
        cin >> site >> pw;
        pws[site] = pw;
    }
    while (m--) {
        string site;
        cin >> site;
        cout << pws[site] << '\n';
    }
}