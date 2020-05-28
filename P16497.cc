#include <bits/stdc++.h>
using namespace std;

int main() {
    int count;
    cin >> count;
    vector<int> begins{count};
    vector<int> ends{count};
    while (count--) {
        int from, to;
        cin >> from >> to;
        begins.push_back(from);
        ends.push_back(to);
    }
    int books;
    cin >> books;
    for (int i = 1; i <= 31; ++i) {
        for (auto& end : ends) {
            if (i == end) {
                ++books;
            }
        }
        for (auto& begin : begins) {
            if (i == begin) {
                --books;
                if (books < 0) {
                    cout << '0';
                    return 0;
                }
            }
        }
    }
    cout << '1';
}