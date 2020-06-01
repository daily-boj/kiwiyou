#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    int mid = 2147483647;
    while (count--) {
        int num;
        cin >> num;
        if (num < mid) {
            left.push(num);
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
        } else if (num > mid) {
            right.push(num);
            if (left.size() < right.size()) {
                left.push(right.top());
                right.pop();
            }
        } else {
            if (left.size() > right.size()) {
                right.push(num);
            } else {
                left.push(num);
            }
        }
        cout << (mid = left.top()) << '\n';
    }
}