#include <bits/stdc++.h>
using namespace std;

tuple<long long, long long, long long> reduce(long long a, long long b, long long c, long long d, long long div) {
    b += a * div;
    c += b * div;
    return { a, b, c };
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fixed;
    while (n--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<double> sol;
        long long sol_0;
        if (d == 0) {
            sol_0 = 0;
        } else {
            for (long long i = 1; i <= sqrt(abs(d)); ++i) {
                if (d % i == 0) {
                    vector<long long> cands = { i, -i, d / i, -d / i };
                    for (auto cand : cands) {
                        if ((((a * cand + b) * cand) + c) * cand + d == 0) {
                            tie(a, b, c) = reduce(a, b, c, d, cand);
                            sol_0 = cand;
                            goto ok;
                        }
                    }
                }
            }
        }
ok:
        sol.push_back(sol_0);
        long long D = b * b - 4 * a * c;
        bool eq = (a * sol_0 + b) * sol_0 + c == 0;
        if (c == 0 && b != 0) {
            sol.push_back(-b / (double) a);
        } else if (D == 0) {
            if (!eq) {
                sol.push_back(-0.5 * b / a);
            }
        } else if (eq) {
            sol.push_back(c / (double) a / sol_0);
        } else if (D > 0) {
            sol.push_back((sqrt(D) - b) / (2 * a));
            sol.push_back((-sqrt(D) - b) / (2 * a));
        }
        sort(sol.begin(), sol.end());
        for (auto solution : sol) {
            cout << solution << ' ';
        }
        cout << '\n';
    }
}