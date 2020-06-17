#include <bits/stdc++.h>
using namespace std;

int select(vector<int> &seq, int begin, int count) {
    int n = (count + 1) >> 1;
    if (n == 2) {
        if ((seq[begin] + seq[begin + 2]) % 2 == 0) {
            swap(seq[begin + 1], seq[begin + 2]);
        } else if ((seq[begin + 1] + seq[begin + 2]) % 2 == 0) {
            swap(seq[begin], seq[begin + 2]);
        }
        return seq[begin] + seq[begin + 1];
    } else {
        int a = select(seq, begin, n - 1);
        int b = select(seq, begin + (n >> 1), n - 1);
        int c = select(seq, begin + n, n - 1);
        if ((a + c) % n == 0) {
            swap_ranges(seq.begin() + begin + (n >> 1), seq.begin() + begin + n, seq.begin() + begin + n);
            return a + c;
        } else if ((b + c) % n == 0) {
            swap_ranges(seq.begin() + begin, seq.begin() + begin + (n >> 1), seq.begin() + begin + n);
            return b + c;
        } else {
            return a + b;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> seq(2 * n - 1);
    for (auto& i : seq) {
        cin >> i;
    }
    select(seq, 0, seq.size());
    for (int i = 0; i < n; ++i) {
        cout << seq[i] << ' ';
    }
}